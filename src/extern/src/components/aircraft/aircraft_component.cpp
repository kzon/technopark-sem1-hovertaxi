#include "aircraft_component.h"

namespace hovertaxi {

std::vector<std::unique_ptr<Aircraft>> AircraftComponent::LoadAircraftInCircle(const GeoPoint &center, int radius) {
  return ServiceLocator::GetDataManager().LoadAircraftsInRadius(center, radius);
}

std::vector<Aircraft> AircraftComponent::LoadCurrentOrderAircraft() {
  return std::vector<Aircraft>();
}

std::vector<std::unique_ptr<AircraftClass>> AircraftComponent::LoadAircraftClasses() {
  return ServiceLocator::GetDataManager().LoadAircraftClasses();
}

std::vector<Pad> AircraftComponent::LoadNearestPads(const GeoPoint &position) {
  return std::vector<Pad>();
}

}
