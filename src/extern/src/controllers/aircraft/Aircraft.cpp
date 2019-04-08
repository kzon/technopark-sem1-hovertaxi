#include "Aircraft.h"
#include "services/servicelocator/ServiceLocator.h"

namespace controllers {

std::string Aircraft::LoadAircraftInCircle(const std::pair<double, double> &center, int radius) {
  return "user_id=" + context.user_id;
}

std::string Aircraft::LoadAircraftClasses() {
  std::string result = services::ServiceLocator::GetDataManager().LoadAircraftClassesAsJSON();
  return result;
}

std::string Aircraft::LoadCurrentOrderAircraft() {
  auto aircraft = services::ServiceLocator::GetDataManager().LoadAircraftById("5ca1f2c9a65e10c9e0a798a2").value();
  std::string result = "id = " + aircraft.id + ", model = " + aircraft.model_id;
  return result;
}

std::string Aircraft::LoadNearestPads(const std::pair<double, double> &position) {
  return {};
}

}