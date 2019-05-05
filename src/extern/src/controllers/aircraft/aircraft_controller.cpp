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
  auto response = ServiceLocator::GetDataManager().LoadAircraftModelById("5063114bd386d8fadbd6b007");
  if (response) {
    auto aircraft = response.value();
    return "id = " + aircraft.id + ", name = " + aircraft.name;
  }
  return "{}";
}

std::string AircraftController::LoadNearestPads(const std::pair<double, double> &position) {
  return {};
}

}