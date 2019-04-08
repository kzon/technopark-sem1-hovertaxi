#include "Aircraft.h"

#include "models/Aircraft.h"
#include "services/servicelocator/ServiceLocator.h"

namespace components {

std::vector<models::Aircraft> Aircraft::LoadAircraftInCircle(const models::GeoPoint &center, int radius) {
  return std::vector<models::Aircraft>();
}

std::vector<models::Aircraft> Aircraft::LoadCurrentOrderAircraft() {
  return std::vector<models::Aircraft>();
}

std::vector<models::AircraftClass> Aircraft::LoadAircraftClasses() {
  return services::ServiceLocator::GetDataManager().LoadAircraftClasses();
}

std::vector<models::Pad> Aircraft::LoadNearestPads(const models::GeoPoint &position) {
  return std::vector<models::Pad>();
}

}
