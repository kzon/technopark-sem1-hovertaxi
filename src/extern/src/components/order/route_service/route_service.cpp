#include "route_service.h"

namespace hovertaxi {

Route RouteService::GetRoute(const Order &order) {
  return {};
}

std::vector<Route> RouteService::GetCrossingRoutes(const Route &route) {
  return std::vector<Route>();
}

int RouteService::GetTimeToArrival(const Order &order) const {
  if (order.status == Order::STATUS_AIRCRAFT_ASSIGNED) {
    Aircraft assigned_aircraft = data_manager_.LoadAircraftById(order.assigned_aircraft_id).value();
    Pad from_pad = data_manager_.LoadPadById(order.from_pad_id).value();
    return 0;
  } else if (order.status == Order::STATUS_ON_FLY) {
    Aircraft assigned_aircraft = data_manager_.LoadAircraftById(order.assigned_aircraft_id).value();
    Pad to_pad = data_manager_.LoadPadById(order.to_pad_id).value();
    return 0;
  }
  return 0;
}

int RouteService::GetTimeFlight(const GeoPoint &p1, const GeoPoint &p2, const AircraftModel &model) const {

  double distance = Geo::DistanceEarth(p1, p2);
  int speed = model.cruise_speed;
  int time = (int)std::round(distance / speed * 60);

  return time;
}

}