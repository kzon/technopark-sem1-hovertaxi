#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include "models/i_json_convertable.h"
#include "models/geo_point.h"

namespace hovertaxi {

class JSONConverter {
 public:
  static std::string ToJSON(bool value);

  static std::string ToJSON(GeoPoint point);

  template<typename T>
  static std::string ToJSON(std::vector<T> &objects);

  static std::string ToJSON(const IJsonConvertable &object);

  template<typename T>
  static std::string ToJSON(const std::unique_ptr<T> &object);
};

// @todo definitions of static methods with templates can not be placed in separate cpp file
template<typename T>
std::string JSONConverter::ToJSON(std::vector<T> &objects) {
  std::stringstream result;
  result << '[';
  bool is_first = true;
  for (const auto &object : objects) {
    if (!is_first)
      result << ',';
    result << ToJSON(object);
    is_first = false;
  }
  result << ']';
  return result.str();
}

template<typename T>
std::string JSONConverter::ToJSON(const std::unique_ptr<T> &object) {
  return ToJSON(*object);
}

}