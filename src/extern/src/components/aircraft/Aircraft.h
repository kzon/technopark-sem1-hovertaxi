#pragma once

#include <vector>

#include "models/Aircraft.h"

namespace components {

class Aircraft {
 public:
  static std::vector<models::Aircraft> LoadAircraftInCircle(models::GeoPoint2D center, int radius);
};

}