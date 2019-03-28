#include "Aircraft.h"

namespace components {

std::vector<models::Aircraft> Aircraft::LoadAircraftInCircle(models::GeoPoint2D center, int radius) {
  std::vector<models::Aircraft> aircraft;
  models::Aircraft v1{"Boeing TDA", models::GeoPoint2D{53.1235, 58.2345}};
  aircraft.push_back(v1);
  return aircraft;
}

}