#pragma once

#include "mongo_data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

class Pad : public MongoDataMapper {
 public:
  std::string name;
  GeoPoint position;

  Pad() {}
  explicit Pad(const MongoDataObject &object) : MongoDataMapper(object) {
    auto data = object.data;
    this->name = data["name"].get_utf8().value.to_string();
    // this->position = ...
  }

  static std::string GetSource() { return "pad"; }
};

}