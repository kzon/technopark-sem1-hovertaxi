#pragma once

#include <chrono>
#include <vector>
#include "DataMapper.h"
#include "GeoPoint.h"

namespace models {

struct Route : public DataMapper {
  std::vector<GeoPoint> points;
  int altitude;
  std::chrono::duration<int> time;
};

}