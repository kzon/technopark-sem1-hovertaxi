#include "Aircraft.h"

#include "models/Aircraft.h"
#include "services/servicelocator/ServiceLocator.h"

namespace components {

std::vector<models::Aircraft> Aircraft::LoadAircraftInCircle(models::GeoPoint center, int radius) {
  std::vector<models::Aircraft> aircraft;
  models::Aircraft a1{"213wq", "Boeing TDA"};
  aircraft.push_back(a1);
  return aircraft;
}

std::vector<models::AircraftClass> Aircraft::LoadAircraftClasses() {
  return services::ServiceLocator::GetDataManager().LoadAircraftClasses();
}

}
