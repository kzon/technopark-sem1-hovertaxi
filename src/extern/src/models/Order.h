#pragma once

#include <memory>
#include <chrono>

#include "GeoPoint2D.h"
#include "Aircraft.h"

namespace models {

struct Order {
  GeoPoint2D from, to;
  std::unique_ptr<Aircraft> assigned_vehicle;
  std::chrono::system_clock::time_point created_date;
};

}