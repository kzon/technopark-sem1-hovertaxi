#pragma once

#include <chrono>
#include <vector>

#include "mongo_data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

class Route : public MongoDataMapper {
 public:
  std::vector<GeoPoint&> points;
  int altitude{};
  std::chrono::duration<int> time{};

  Route() = default;
  explicit Route(const MongoDataObject &object) : MongoDataMapper(object) {
    auto data = object.data;
    //this->points = ...
    this->altitude = data["altitude"].get_int64().value;
    //this->time = ...
  };

  static std::string GetSource() { return "route"; }

  std::map<std::string, std::string> GetJsonFields() const override {
    auto fields = MongoDataMapper::GetJsonFields();
    //fields["points"] = JsonConverter::ToJSON(points);
    fields["altitude"] = std::to_string(altitude);
    fields["time"] = std::to_string(time.count()) + " minutes";
    return fields;
  }
};

}