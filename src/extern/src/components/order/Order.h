#pragma once

#include <vector>

#include "models/Order.cpp"
#include "models/GeoPoint.cpp"

namespace components {

class Order {
 public:
  static bool LoadOrderById(unsigned order_id, models::Order &order);
  static models::Order CreateOrder(unsigned user_id, models::GeoPoint &from, models::GeoPoint &to);
  static models::Order ProcessOrder(unsigned order_id);
};

}
