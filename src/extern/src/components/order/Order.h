#pragma once

#include <vector>

#include "models/Order.cpp"
#include "models/GeoPoint.cpp"

namespace components {

class Order {
 public:
  std::vector<models::Order> LoadOrders();
  models::Order CreateOrder(models::GeoPoint &from, models::GeoPoint &to);
};

}
