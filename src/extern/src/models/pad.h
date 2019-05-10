#pragma once

#include "mongo_data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

class Pad : public MongoDataMapper {
 public:
  std::string name;
  GeoPoint position{};

  Pad() = default;
  explicit Pad(const MongoDataObject &object) : MongoDataMapper(object) {
    auto view = object.view();
    this->name = view["name"].get_utf8().value.to_string();
    auto coordinates = view["position"].get_document().view()["coordinates"].get_array().value;
    this->position = GeoPoint{coordinates[0].get_double(), coordinates[1].get_double()};
  }

  static std::string GetSource() { return "pad"; }

  std::map<std::string, std::string> GetJsonFields() const override {
    auto fields = MongoDataMapper::GetJsonFields();
    fields["name"] = name;
    fields["position"] = JSON::ToJSON(position);
    return fields;
  }
};

}