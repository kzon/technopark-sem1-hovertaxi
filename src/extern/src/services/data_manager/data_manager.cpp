#include "data_manager.h"

namespace hovertaxi {

DataManager &hovertaxi::DataManager::GetInstance(const std::string &uri) {
  static DataManager instance(uri);
  return instance;
}

core::optional<Aircraft> DataManager::LoadAircraftById(const std::string &id) const {
  Optional<MongoDataObject> result = db_.LoadObjectById(Aircraft::GetSource(), id);
  if (result) {
    Aircraft aircraft(result.value());
    return core::optional<Aircraft>(aircraft);
  }
  return {};
}

std::string DataManager::LoadAircraftClassesAsJSON() const {
  return db_.LoadObjectsAsJSON(AircraftClass::GetSource());
}

}