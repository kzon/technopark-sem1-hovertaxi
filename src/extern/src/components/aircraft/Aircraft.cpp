#include "Aircraft.h"

#include <models/Aircraft.h>

namespace components {

std::vector<models::Aircraft> Aircraft::LoadAircraftInCircle(models::GeoPoint2D center, int radius) {
  std::vector<models::Aircraft> aircraft;
  models::Aircraft a1{"213wq", "Boeing TDA"};
  aircraft.push_back(a1);
  return aircraft;
}

}
