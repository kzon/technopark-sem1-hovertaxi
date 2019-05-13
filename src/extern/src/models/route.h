#pragma once

#include <chrono>
#include <vector>

#include "mongo_data_mapper.h"
#include "geo_point.h"
#include "services/json/json.h"

namespace hovertaxi {

class Route : public IJsonConvertable {
 public:
  std::vector<GeoPoint> points;
  int altitude{};
  int time{};

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["points"] = JSON::ToJSON<GeoPoint>(points, true);
    fields["altitude"] = std::to_string(altitude);
    fields["time"] = std::to_string(time);
    return fields;
  }
};

}