#pragma once

#include <chrono>
#include <vector>

#include "mongo_data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

class Route : public MongoDataMapper {
 public:
  std::vector<GeoPoint> points;
  int altitude;
  std::chrono::duration<int> time;
};

}