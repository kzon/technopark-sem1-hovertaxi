#pragma once

#include <vector>

#include "models/aircraft.h"
#include "models/aircraft_class.h"
#include "models/geo_point.h"
#include "models/pad.h"

namespace hovertaxi  {

class AircraftComponent {
 public:
  static std::vector<Aircraft> LoadAircraftInCircle(GeoPoint center, int radius);
  static std::vector<Aircraft> LoadCurrentOrderAircraft();
  static std::vector<AircraftClass> LoadAircraftClasses();
  static std::vector<Pad> LoadPadsInCircle(GeoPoint center, int radius);
};

}