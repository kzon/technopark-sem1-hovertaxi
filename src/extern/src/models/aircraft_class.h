#pragma once

#include "mongo_data_mapper.h"

namespace hovertaxi {

class AircraftClass : public MongoDataMapper {
 public:
  std::string name;
  int min_range;
  int max_range;

  AircraftClass() {}
  explicit AircraftClass(const MongoDataObject &object) {
    auto data = object.data;
    this->name = data["name"].get_utf8().value.to_string();
    this->min_range = data["min_range"].get_int64().value;
    this->max_range = data["max_range"].get_int64().value;
  }

  static std::string GetSource() { return "aircraft_class"; }
};

}