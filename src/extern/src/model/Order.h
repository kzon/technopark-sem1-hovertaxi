#pragma once

#include <chrono>

#include "GeoPoint.h"
#include "Vehicle.h"

namespace model {

struct Order {
  GeoPoint from{}, to{};
  Vehicle assigned_vehicle;
  std::chrono::system_clock::time_point created_date;
};

}