#include "aircraft_controller.h"

namespace hovertaxi {

std::string AircraftController::LoadAircraftInCircle(const std::pair<double, double> &center, int radius) {
  return "user_id=" + context.user_id;
}

std::string AircraftController::LoadAircraftClasses() {
  auto aircraft_classes = AircraftComponent::LoadAircraftClasses();
  return JSONConverter::ToJSON(aircraft_classes);
}

std::string AircraftController::LoadCurrentOrderAircraft() {
  auto result = ServiceLocator::GetDataManager().LoadAircraftById("5ccffc86a8ef5bdef367710f");
  if (result)
    return JSONConverter::ToJSON(result.value());
  return "null";
}

std::string AircraftController::LoadNearestPads(const std::pair<double, double> &position) {
  return {};
}

}