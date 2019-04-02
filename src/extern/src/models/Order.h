#pragma once

#include <memory>
#include <chrono>

#include "GeoPoint.h"
#include "Aircraft.h"
#include "Pad.h"

namespace models {

enum OrderStatus {
  NEW,
  PROCESSING,
  AIRCRAFT_ASSIGNED,
  ON_FLY,
  FINISHED,
  CANCELED
};

struct Order {
  std::string user_id;
  OrderStatus status;
  GeoPoint from, to;
  Pad from_pad, to_pad;
  std::string aircraft_class_id;
  std::string assigned_aircraft_id;
};

}