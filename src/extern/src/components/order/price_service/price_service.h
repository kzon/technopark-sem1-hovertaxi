#pragma once

#include "services/data_manager/data_manager.h"
#include "../route_service/route_service.h"
#include "services/geo/geo.h"
#include "models/aircraft_class.h"
#include "models/aircraft_model.h"
#include "models/geo_point.h"
#include "models/order.h"

namespace hovertaxi {

class PriceService {
 public:
  PriceService(): data_manager_(DataManager::GetInstance()) {}

  int GetPrice(const GeoPoint &p1, const GeoPoint &p2, const AircraftModel &model) const;
  int GetCancelPrice(const Order &order) const;

 private:
  RouteService route_service_;
  const DataManager &data_manager_;
};

}