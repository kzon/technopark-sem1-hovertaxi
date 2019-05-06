#pragma once

#include <string>
#include <bsoncxx/json.hpp>
#include "models/geo_point.h"
#include "data_filter.h"

namespace hovertaxi {

class DataFilterCondition {
 public:
  static void StringEquals(DataFilter &filter, const std::string &field, const std::string &value);
  static void GeoPointInRadius(DataFilter &filter,
                               const std::string &field,
                               const GeoPoint &center,
                               int radius);
};

}