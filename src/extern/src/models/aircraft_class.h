#pragma once

#include "mongo_data_mapper.h"

namespace hovertaxi {

class AircraftClass : public MongoDataMapper {
 public:
  std::string name;
  int min_range{};
  int max_range{};

  AircraftClass() = default;
  explicit AircraftClass(const MongoDataObject &object) : MongoDataMapper(object) {
    auto data = object.data;
    this->name = data["name"].get_utf8().value.to_string();
    this->min_range = data["min_range"].get_int32().value;
    this->max_range = data["max_range"].get_int32().value;
  }

  static std::string GetSource() { return "aircraft_class"; }

  std::map<std::string, std::string> GetJsonFields() const override {
    auto fields = MongoDataMapper::GetJsonFields();
    fields["name"] = name;
    fields["min_range"] = std::to_string(min_range);
    fields["max_range"] = std::to_string(max_range);
    return fields;
  }
};

}