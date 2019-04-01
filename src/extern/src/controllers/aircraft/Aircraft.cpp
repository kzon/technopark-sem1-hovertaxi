#include "Aircraft.h"
#include "services/servicelocator/ServiceLocator.h"

namespace controllers {

std::string Aircraft::LoadAircraftInCircle() {
  optional<models::Aircraft> aircraft =
      services::ServiceLocator::GetDataManager().LoadAircraftById("5ca1f2c9a65e10c9e0a798a2");
  if (aircraft) {
    return aircraft.value().model;
  }
  return "not found";
}

}