#pragma once

#include <memory>
#include <chrono>

#include "GeoPoint.cpp"
#include "Vehicle.cpp"

namespace models {

enum OrderStatus {
  NEW,
  PROCESSING,
  VEHICLE_ASSIGNED,
  ON_TRIP,
  FINISHED,
};

struct Order {
  unsigned id;
  unsigned user_id;
  GeoPoint from, to;
  std::unique_ptr<Vehicle> assigned_vehicle;
  double time_to_arrival;
  OrderStatus status;
  std::chrono::system_clock::time_point created_date;
};

}