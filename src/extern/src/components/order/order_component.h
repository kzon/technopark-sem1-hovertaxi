#pragma once

#include <string>

#include "models/order.h"
#include "models/geo_point.h"
#include "models/aircraft_class.h"

namespace hovertaxi {

class OrderComponent {
 public:
  static std::string PreOrder(GeoPoint from, GeoPoint to, AircraftClass aircraft_class);
  static Order CreateOrder(std::string user_id, GeoPoint &from, GeoPoint &to);
  static Order ProcessOrder(std::string order_id);
};

}