#pragma once

#include <memory>
#include <chrono>

#include "geo_point.h"
#include "aircraft.h"
#include "pad.h"

namespace hovertaxi {

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