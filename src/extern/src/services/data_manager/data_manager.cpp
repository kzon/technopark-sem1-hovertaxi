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

std::vector<AircraftClass> DataManager::LoadAircraftClasses() const {
  auto objects = db_.LoadObjects(AircraftClass::GetSource());
  std::vector<AircraftClass> result(objects.size());
  for (const auto &object : objects)
    result.emplace_back(object);
  return result;
}

std::string DataManager::LoadAircraftByIdAsJSON(const std::string &id) const {
  return db_.LoadObjectByIdAsJSON(Aircraft::GetSource(), id);
}

std::string DataManager::LoadAircraftClassesAsJSON() const {
  return db_.LoadObjectsAsJSON(AircraftClass::GetSource());
}

}