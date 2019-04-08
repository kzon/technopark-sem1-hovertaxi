#include "aircraft_controller.h"
#include "services/service_locator/service_locator.h"

namespace hovertaxi {

std::string AircraftController::LoadAircraftInCircle(const std::pair<double, double> &center, int radius) {
  return "user_id=" + context.user_id;
}

std::string AircraftController::LoadAircraftClasses() {
  std::string result = ServiceLocator::GetDataManager().LoadAircraftClassesAsJSON();
  return result;
}

std::string AircraftController::LoadCurrentOrderAircraft() {
  auto aircraft = ServiceLocator::GetDataManager().LoadAircraftById("5ca1f2c9a65e10c9e0a798a2").value();
  std::string result = "id = " + aircraft.id + ", model = " + aircraft.model_id;
  return result;
}

std::string AircraftController::LoadNearestPads(const std::pair<double, double> &position) {
  return {};
}

}