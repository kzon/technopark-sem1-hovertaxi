#include "price_service.h"

namespace hovertaxi {

int PriceService::GetPrice(const Order &order) {
  return 0;
}

int PriceService::GetCancelPrice(const Order &order) {
  return 0;
}

int PriceService::GetTimeFlight(const GeoPoint &p1, const GeoPoint &p2, const AircraftModel &model) {

  double distance = Geo::DistanceEarth(p1, p2);
  int speed = model.cruise_speed;
  int time = (int)std::round(distance / speed * 60);

  return time;
}

int PriceService::GetPrice(const GeoPoint &p1, const GeoPoint &p2, const AircraftModel &model) {

  DataManager &data_manager_ = DataManager::GetInstance();

  Optional<AircraftClass> aircraft_class_result = data_manager_.LoadAircraftClassById(model.class_id);
  if (!aircraft_class_result)
    throw std::bad_exception();
  AircraftClass aircraft_class = aircraft_class_result.value();

  int time = GetTimeFlight(p1, p2, model);
  int cost = time * aircraft_class.cost;
  return cost;
}

int PriceService::GetCancelPrice(const GeoPoint &p1, const GeoPoint &p2, const AircraftModel &model) {
  return 0;
}

}