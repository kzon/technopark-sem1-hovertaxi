#pragma once

#include "mongo_data_mapper.h"

namespace hovertaxi {

class AircraftModel : public MongoDataMapper {
 public:
  std::string name;
  std::string class_id;
  int cruise_speed;

  AircraftModel() {}
  explicit AircraftModel(const MongoDataObject &object) : MongoDataMapper(object) {
    auto data = object.data;
    this->name = data["name"].get_utf8().value.to_string();
    this->class_id = data["class_id"].get_utf8().value.to_string();
    this->cruise_speed = data["cruise_speed"].get_int64().value;
  }

  static std::string GetSource() { return "aircraft_model"; }
};

}