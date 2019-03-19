#pragma once

#include <vector>

#include "models/Order.cpp"
#include "models/GeoPoint.cpp"

namespace components {

class Order {
 public:
  static std::vector<models::Order> LoadOrders();
  static models::Order CreateOrder(models::GeoPoint &from, models::GeoPoint &to);
};

}
