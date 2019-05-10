#include "aircraft_component.h"

namespace hovertaxi {

std::vector<std::unique_ptr<Aircraft>> AircraftComponent::LoadAircraftInCircle(const GeoPoint &center, int radius) {
  return data_manager_.LoadAircraftsInRadius(center, radius);
}

Aircraft AircraftComponent::LoadCurrentOrderAircraft() {
  return {};
}

std::vector<std::unique_ptr<AircraftClass>> AircraftComponent::LoadAircraftClasses() {
  return data_manager_.LoadAircraftClasses();
}

std::vector<std::unique_ptr<Pad>> AircraftComponent::LoadNearestPads(const GeoPoint &position) {
  return data_manager_.LoadPadsInRadius(position, 50000);
}

}
