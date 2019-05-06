#include "aircraft_component.h"

namespace hovertaxi {

std::vector<std::unique_ptr<Aircraft>> AircraftComponent::LoadAircraftInCircle(const GeoPoint &center, int radius) {
  return ServiceLocator::GetDataManager().LoadAircraftsInRadius(center, radius);
}

Aircraft AircraftComponent::LoadCurrentOrderAircraft() {
  return {};
}

std::vector<std::unique_ptr<AircraftClass>> AircraftComponent::LoadAircraftClasses() {
  return ServiceLocator::GetDataManager().LoadAircraftClasses();
}

std::vector<std::unique_ptr<Pad>> AircraftComponent::LoadNearestPads(const GeoPoint &position) {
  return ServiceLocator::GetDataManager().LoadPadsInRadius(position, 50000);
}

}
