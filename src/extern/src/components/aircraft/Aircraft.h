#pragma once

#include <vector>

#include "core/context_keeper.h"
#include "models/Aircraft.h"
#include "models/AircraftClass.h"
#include "models/GeoPoint.h"
#include "models/Pad.h"

namespace components {

class Aircraft : public ContextKeeper {
 public:
  static std::vector<models::Aircraft> LoadAircraftInCircle(const models::GeoPoint &center, int radius);
  static std::vector<models::Aircraft> LoadCurrentOrderAircraft();
  static std::vector<models::AircraftClass> LoadAircraftClasses();
  static std::vector<models::Pad> LoadNearestPads(const models::GeoPoint &position);
};

}