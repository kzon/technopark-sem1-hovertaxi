#include "aircraft_controller.h"

namespace hovertaxi {

std::string AircraftController::LoadAircraftInCircle(const std::pair<double, double> &center, int radius) {
  auto aircraft_classes = AircraftComponent::LoadAircraftInCircle(GeoPoint{center.first, center.second}, radius);
  return JSONConverter::ToJSON(aircraft_classes);
}

std::string AircraftController::LoadAircraftClasses() {
  auto aircraft_classes = AircraftComponent::LoadAircraftClasses();
  return JSONConverter::ToJSON(aircraft_classes);
}

std::string AircraftController::LoadCurrentOrderAircraft() {
  auto aircraft = AircraftComponent::LoadCurrentOrderAircraft();
  return JSONConverter::ToJSON(aircraft);
}

std::string AircraftController::LoadNearestPads(const std::pair<double, double> &position) {
  auto pads = AircraftComponent::LoadNearestPads(GeoPoint{position.first, position.second});
  return JSONConverter::ToJSON(pads);
}

}