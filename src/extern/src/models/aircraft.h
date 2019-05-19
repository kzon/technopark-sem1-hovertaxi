#pragma once

#include <string>

#include "mongo_data_mapper.h"
#include "geo_point.h"
#include "services/json/json.h"

namespace hovertaxi {

class Aircraft : public MongoDataMapper {
 public:
  std::string model_id;
  std::string number;
  GeoPoint position{};
  int speed{};
  int direction{};
  bool is_assigned{};

  Aircraft() = default;
  explicit Aircraft(const MongoDataObject &object) : MongoDataMapper(object) {
    auto view = object.view();
    this->model_id = view["model_id"].get_utf8().value.to_string();
    this->number = view["number"].get_utf8().value.to_string();

    auto coordinates = view["position"].get_document().view()["coordinates"].get_array().value;
    this->position = GeoPoint{coordinates[0].get_double(), coordinates[1].get_double()};

    this->speed = view["speed"].get_int32().value;
    this->direction = view["direction"].get_int32().value;
    this->is_assigned = view["is_assigned"].get_bool().value;
  }

  static std::string GetSource() { return "aircraft"; }

  std::map<std::string, std::string> GetJsonFields() const override {
    auto fields = MongoDataMapper::GetJsonFields();
    fields["model_id"] = model_id;
    fields["number"] = number;
    fields["position"] = JSON::ToJSON(position);
    fields["speed"] = std::to_string(speed);
    fields["direction"] = std::to_string(direction);
    fields["is_assigned"] = JSON::ToJSON(is_assigned);
    return fields;
  }

  MongoDataObject GetStorageObject() const override {
    auto object = bsoncxx::builder::stream::document{}
        << "model_id" << model_id
        << "number" << number
        << "speed" << speed
        << "direction" << direction
        << "is_assigned" << is_assigned
        << bsoncxx::builder::stream::finalize;
    return object;
  }
};

}