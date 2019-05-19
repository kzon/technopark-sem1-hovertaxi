#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include "core/optional.h"
#include "models/i_json_convertable.h"
#include "models/geo_point.h"

namespace hovertaxi {

class JSON {
 public:
  static std::string ToJSON(bool value, bool escape = false);

  static std::string ToJSON(GeoPoint point, bool escape = false);

  template<typename T>
  static std::string ToJSON(const std::vector<T> &objects, bool escape = false);

  static std::string ToJSON(const IJsonConvertable &object, bool escape = false);

  template<typename T>
  static std::string ToJSON(const std::unique_ptr<T> &object, bool escape = false);

  static std::string Empty() { return "null"; };
};

// @todo definitions of static methods with templates can not be placed in separate cpp file
template<typename T>
std::string JSON::ToJSON(const std::vector<T> &objects, bool escape) {
  std::stringstream result;
  result << '[';
  bool is_first = true;
  for (const auto &object : objects) {
    if (!is_first)
      result << ',';
    result << ToJSON(object, escape);
    is_first = false;
  }
  result << ']';
  return result.str();
}

template<typename T>
std::string JSON::ToJSON(const std::unique_ptr<T> &object, bool escape) {
  return ToJSON(*object, escape);
}

}