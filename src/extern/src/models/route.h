#pragma once

#include <chrono>
#include <vector>

#include "mongo_data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

class Route : public MongoDataMapper {
 public:
  std::vector<GeoPoint> points;
  int altitude{};
  std::chrono::duration<int> time{};

  Route() = default;
  explicit Route(const MongoDataObject &object) : MongoDataMapper(object) {
    //this->points = ...
    this->altitude = object.view()["altitude"].get_int32().value;
    //this->time = ...
  };

  static std::string GetSource() { return "route"; }

  std::map<std::string, std::string> GetJsonFields() const override {
    auto fields = MongoDataMapper::GetJsonFields();
    fields["altitude"] = std::to_string(altitude);
    return fields;
  }
};

}