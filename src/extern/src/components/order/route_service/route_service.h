#pragma once

#include <vector>
#include "models/route.h"
#include "models/order.h"

namespace hovertaxi {

class RouteService {
 public:
  static Route GetRoute(const Order &order);
  static std::vector<Route> GetCrossingRoutes(const Route &route);
};

}