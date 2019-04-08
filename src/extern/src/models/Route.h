#pragma once

#include <chrono>
#include <vector>
#include "data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

struct Route : public DataMapper {
  std::vector<GeoPoint> points;
  std::chrono::duration<int> time;
};

}