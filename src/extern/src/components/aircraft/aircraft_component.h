#pragma once

#include <vector>

#include "core/context_keeper.h"
#include "models/aircraft.h"
#include "models/aircraft_class.h"
#include "models/geo_point.h"
#include "models/pad.h"
#include "services/service_locator/service_locator.h"

namespace hovertaxi {

class AircraftComponent : public ContextKeeper {
 public:
  static std::vector<std::unique_ptr<Aircraft>> LoadAircraftInCircle(const GeoPoint &center, int radius);
  static std::vector<Aircraft> LoadCurrentOrderAircraft();
  static std::vector<std::unique_ptr<AircraftClass>> LoadAircraftClasses();
  static std::vector<Pad> LoadNearestPads(const GeoPoint &position);
};

}