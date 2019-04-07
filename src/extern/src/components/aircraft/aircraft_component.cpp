#include "Aircraft.h"

#include "models/aircraft_component.h"
#include "services/servicelocator/service_locator.h"

namespace hovertaxi {

std::vector<Aircraft> AircraftComponent::LoadAircraftInCircle(GeoPoint center, int radius) {
  std::vector<Aircraft> aircraft;
  Aircraft a1{"213wq", "Boeing TDA"};
  aircraft.push_back(a1);
  return aircraft;
}

std::vector<AircraftClass> AircraftComponent::LoadAircraftClasses() {
  return ServiceLocator::GetDataManager().LoadAircraftClasses();
}

}
