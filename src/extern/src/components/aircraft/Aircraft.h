#pragma once

#include <vector>

#include "models/Aircraft.h"
#include "models/AircraftClass.h"
#include "models/GeoPoint.h"
#include "models/Pad.h"

namespace components {

class Aircraft {
 public:
  static std::vector<models::Aircraft> LoadAircraftInCircle(models::GeoPoint center, int radius);
  static std::vector<models::Aircraft> LoadCurrentOrderAircraft();
  static std::vector<models::AircraftClass> LoadAircraftClasses();
  static std::vector<models::Pad> LoadPadsInCircle(models::GeoPoint center, int radius);
};

}