#pragma once

#include <vector>
#include "models/route.h"
#include "models/order.h"

namespace hovertaxi {

class RouteService {
 public:
  Route GetRoute(const Order &order);
  std::vector<Route> GetCrossingRoutes(const Route &route);
};

}