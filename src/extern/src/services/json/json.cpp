#include "json.h"

namespace hovertaxi {

std::string JSON::ToJSON(const IJsonConvertable &object) {
  std::stringstream result;
  result << '{';
  bool is_first = true;
  for (const auto &field : object.GetJsonFields()) {
    if (!is_first)
      result << ',';
    result << '"' << field.first << "\":";
    result << '"' << field.second << '"';
    is_first = false;
  }
  result << '}';
  return result.str();
}

std::string JSON::ToJSON(GeoPoint point) {
  std::stringstream result;
  result << "[" << point.latitude << "," << point.longitude << "]";
  return result.str();
}

std::string JSON::ToJSON(bool value) {
  return value ? "true" : "false";
}

}