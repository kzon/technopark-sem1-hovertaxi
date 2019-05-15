#include "json.h"

namespace hovertaxi {

std::string JSON::ToJSON(const IJsonConvertable &object, bool escape) {
  std::stringstream result;
  result << '{';
  bool is_first = true;
  std::string quote = escape ? "\\\"" : "\"";
  for (const auto &field : object.GetJsonFields()) {
    if (!is_first)
      result << ',';
    result << quote << field.first << quote << ":";
    result << quote << field.second << quote;
    is_first = false;
  }
  result << '}';
  return result.str();
}

std::string JSON::ToJSON(GeoPoint point, bool escape) {
  std::stringstream result;
  result << "[" << point.latitude << "," << point.longitude << "]";
  return result.str();
}

std::string JSON::ToJSON(bool value, bool escape) {
  return value ? "true" : "false";
}

}