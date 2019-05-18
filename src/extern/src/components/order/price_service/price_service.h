#pragma once

#include "services/data_manager/data_manager.h"
#include "services/geo/geo.h"
#include "models/aircraft_class.h"
#include "models/aircraft_model.h"
#include "models/geo_point.h"
#include "models/order.h"

namespace hovertaxi {

class PriceService {
 public:
  static int GetPrice(const Order &order);
  static int GetCancelPrice(const Order &order);

  //returns time in minutes
  static int GetTimeFlight(const GeoPoint &p1, const GeoPoint &p2, const AircraftModel &model);
  static int GetPrice(const GeoPoint &p1, const GeoPoint &p2, const AircraftModel &model);
  static int GetCancelPrice(const GeoPoint &p1, const GeoPoint &p2, const AircraftModel &model);
};

}