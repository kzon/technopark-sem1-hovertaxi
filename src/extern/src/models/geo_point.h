#pragma once

#include "i_json_convertable.h"
#include "services/json_converter/json_converter.h"

namespace hovertaxi {

class GeoPoint : public IJsonConvertable {
 public:
  double latitude{};
  double longitude{};

  GeoPoint() = default;
  GeoPoint(double latitude, double longitude) : latitude(latitude), longitude(longitude) {}

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["latitude"] = std::to_string(latitude);
    fields["longitude"] = std::to_string(longitude);
    return fields;
  }
};

}