#include "Aircraft.h"
#include "components/aircraft/Aircraft.h"

namespace controllers {

std::string Aircraft::LoadAircraftInCircle() {
  auto aircrafts = components::Aircraft::LoadAircraftInCircle(models::GeoPoint2D{54.124234, 43.4234}, 5);
  std::string result;
  for (const auto &aircraft : aircrafts) {
    result += aircraft.model + " on ";
    result += std::to_string(aircraft.position.longitude) + ", "
        + std::to_string(aircraft.position.latitude);
    result += '\n';
  }
  return result;
}

}