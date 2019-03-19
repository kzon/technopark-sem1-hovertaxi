#pragma once

#include <memory>
#include <chrono>

#include "GeoPoint.cpp"
#include "Vehicle.cpp"

namespace models {

struct Order {
  GeoPoint from, to;
  std::unique_ptr<Vehicle> assigned_vehicle;
  std::chrono::system_clock::time_point created_date;
};

}