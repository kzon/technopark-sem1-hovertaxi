#pragma once

#include <string>
#include <vector>
#include <bsoncxx/json.hpp>
#include "models/geo_point.h"
#include "data_filter.h"

namespace hovertaxi {

class DataFilterBuilder {
 public:
  static void StringEquals(DataFilter &filter, const std::string &field, const std::string &value);
  static void StringNotEquals(DataFilter &filter, const std::string &field, const std::string &value);
  static void StringIn(DataFilter &filter, const std::string &field, const std::vector<std::string> &values);
  static void BoolEquals(DataFilter &filter, const std::string &field, bool value);
  static void GeoPointNear(DataFilter &filter,
                           const std::string &field,
                           const GeoPoint &center,
                           int radius);
};

}