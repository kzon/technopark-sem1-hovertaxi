#pragma once

#include <string>

#include "models/Order.h"
#include "models/GeoPoint.h"
#include "models/AircraftClass.h"

namespace components {

class Order {
 public:
  static std::string GetOrderInfo(models::GeoPoint from, models::GeoPoint to, models::AircraftClass aircraft_class);
  static models::Order CreateOrder(std::string user_id, models::GeoPoint &from, models::GeoPoint &to);
  static models::Order ProcessOrder(std::string order_id);
};

}