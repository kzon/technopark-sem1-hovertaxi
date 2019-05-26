#include "price_service.h"

namespace hovertaxi {

// price = s / v * coef(aircraft_class)
int PriceService::GetPrice(const GeoPoint &p1, const GeoPoint &p2, const AircraftModel &model) const {
  Optional<AircraftClass> aircraft_class_result = data_manager_.LoadAircraftClassById(model.class_id);
  if (!aircraft_class_result)
    throw std::bad_exception();
  AircraftClass aircraft_class = aircraft_class_result.value();

  int time_in_seconds = route_service_.GetTimeBetweenPointsInMinutes(p1, p2, model) * 60;
  int cost = time_in_seconds * aircraft_class.cost;
  return cost;
}

// cancelPrice = (current distance / total distance  * price) / 2
int PriceService::GetCancelPrice(const Order &order) const {
  Optional<Pad> from_pad_result = data_manager_.LoadPadById(order.from_pad_id),
      to_pad_result = data_manager_.LoadPadById(order.to_pad_id);
  if (!from_pad_result || !to_pad_result)
    throw std::bad_exception();
  Pad from_pad = from_pad_result.value(),
      to_pad = to_pad_result.value();

  Optional<Aircraft>
      aircraft_result = data_manager_.LoadNearestFreeAircraft(from_pad.position, order.aircraft_class_id);
  if (!aircraft_result)
    throw std::bad_exception();
  Aircraft aircraft = aircraft_result.value();

  GeoPoint from = from_pad.position;
  GeoPoint current = aircraft.position;

  double current_distance = Geo::DistanceEarth(from, current);
  double total_distance = Geo::DistanceEarth(from_pad.position, to_pad.position);
  int cancelPrice = (int) (current_distance / total_distance * order.price / 2);

  return cancelPrice;
}

}