#pragma once

#include <vector>

#include "models/Aircraft.h"
#include "models/GeoPoint2D.h"

namespace components {

class Aircraft {
 public:
  static std::vector<models::Aircraft> LoadAircraftInCircle(models::GeoPoint2D center, int radius);
};

}