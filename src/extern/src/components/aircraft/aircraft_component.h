#pragma once

#include <vector>

#include "core/context_keeper.h"
#include "models/aircraft.h"
#include "models/aircraft_class.h"
#include "models/geo_point.h"
#include "models/pad.h"

namespace hovertaxi {

class AircraftComponent: public ContextKeeper {
 public:
  static std::vector<Aircraft> LoadAircraftInCircle(const GeoPoint &center, int radius);
  static std::vector<Aircraft> LoadCurrentOrderAircraft();
  static std::vector<AircraftClass> LoadAircraftClasses();
  static std::vector<Pad> LoadNearestPads(const GeoPoint &position);
};

}