#include "Aircraft.h"

namespace components {

std::vector<models::Aircraft> Aircraft::LoadAircraftInCircle(models::GeoPoint2D center, int radius) {
  std::vector<models::Aircraft> aircraft;
  models::Aircraft a1{"Boeing TDA", center};
  aircraft.push_back(a1);
  return aircraft;
}

}