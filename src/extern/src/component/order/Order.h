#pragma once

#include <vector>

#include "../../model/Order.h"
#include "../../model/GeoPoint.h"

namespace component {

class Order {
 public:
  std::vector<model::Order> loadOrders();
  model::Order createOrder(model::GeoPoint &from, model::GeoPoint &to);
};

}
