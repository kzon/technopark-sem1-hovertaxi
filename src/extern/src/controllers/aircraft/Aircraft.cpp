#include "Aircraft.h"
#include "services/servicelocator/ServiceLocator.h"

namespace controllers {

std::string Aircraft::LoadAircraftInCircle() {
  auto aircraft = services::ServiceLocator::GetDataManager().LoadAircraftById("5ca1f2c9a65e10c9e0a798a2").value();
  std::string result = "id = " + aircraft.id + ", model = " + aircraft.model;
  return result;
}

}