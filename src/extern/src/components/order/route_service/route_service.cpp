#include "route_service.h"

namespace hovertaxi {

Route RouteService::GetRoute(const Order &order) {
  return {};
}

std::vector<Route> RouteService::GetCrossingRoutes(const Route &route) {
  return std::vector<Route>();
}

}