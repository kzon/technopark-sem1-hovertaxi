#pragma once

#include "mongo_data_mapper.h"

namespace hovertaxi {

class AircraftModel : public MongoDataMapper {
 public:
  std::string name;
  std::string class_id;
  int cruise_speed{};

  AircraftModel() = default;
  explicit AircraftModel(const MongoDataObject &object) : MongoDataMapper(object) {
    auto view = object.view();
    this->name = view["name"].get_utf8().value.to_string();
    this->class_id = view["class_id"].get_utf8().value.to_string();
    this->cruise_speed = view["cruise_speed"].get_int32().value;
  }

  static std::string GetSource() { return "aircraft_model"; }

  std::map<std::string, std::string> GetJsonFields() const override {
    auto fields = MongoDataMapper::GetJsonFields();
    fields["name"] = name;
    fields["class_id"] = class_id;
    fields["cruise_speed"] = std::to_string(cruise_speed);
    return fields;
  }
};

}