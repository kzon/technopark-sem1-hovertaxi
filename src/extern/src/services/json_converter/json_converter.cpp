#include <string>
#include <sstream>
#include <vector>
#include "json_converter.h"

namespace hovertaxi {

std::string JsonConverter::ToJSON(const IJsonConvertable &object) {
  std::stringstream result;
  result << "{";
  bool is_first = true;
  for (const auto &field : object.GetJsonFields()) {
    if (!is_first)
      result << ",";
    result << "\"" << field.first << "\":";
    result << "\"" << field.second << "\"";
    is_first = false;
  }
  result << "}";
  return result.str();
}

}