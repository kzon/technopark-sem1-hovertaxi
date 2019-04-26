#pragma once

#include "mongo_data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

class Pad : public MongoDataMapper {
 public:
  std::string name;
  GeoPoint position;

  Pad() = default;
  explicit Pad(const MongoDataObject &object) : MongoDataMapper(object) {
    auto data = object.data;
    this->name = data["name"].get_utf8().value.to_string();
    // this->position = ...
  }

  static std::string GetSource() { return "pad"; }

  std::map<std::string, std::string> GetJsonFields() const override {
    auto fields = MongoDataMapper::GetJsonFields();
    fields["name"] = name;
    fields["position"] = JsonConverter::ToJSON(position);
    return fields;
  }
};

}