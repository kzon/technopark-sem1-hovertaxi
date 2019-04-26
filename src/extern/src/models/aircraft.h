#pragma once

#include <string>

#include "mongo_data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

class Aircraft : public MongoDataMapper {
 public:
  std::string model_id;
  std::string number;
  GeoPoint position;
  int speed{};
  int direction{};
  bool is_assigned{};

  Aircraft() = default;
  explicit Aircraft(const MongoDataObject &object) : MongoDataMapper(object) {
    auto data = object.data;
    this->model_id = data["model_id"].get_oid().value.to_string();
    //this->position = ...
    this->speed = data["speed"].get_int64().value;
    this->direction = data["direction"].get_int64().value;
    this->is_assigned = data["is_assigned"].get_bool().value;
  }

  static std::string GetSource() { return "aircraft"; }

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["model_id"] = model_id;
    fields["number"] = number;
    fields["position"] = JsonConverter::ToJSON(position);
    fields["speed"] = std::to_string(speed);
    fields["direction"] = std::to_string(direction);
    fields["is_assigned"] = std::to_string(is_assigned);
    return fields;
  }
};

}