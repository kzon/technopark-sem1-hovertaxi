#include "storage_manager.h"

namespace hovertaxi {

StorageManager &hovertaxi::StorageManager::GetInstance(const std::string &uri) {
  static StorageManager instance(uri);
  return instance;
}

core::optional<Aircraft> StorageManager::LoadAircraftById(const std::string &id) const {
  auto result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  if (result) {
    Aircraft aircraft = db_converter.ToDataMapper<Aircraft>(result.value().view());
    return core::optional<Aircraft>(aircraft);
  }
  return {};
}
std::vector<AircraftClass> StorageManager::LoadAircraftClasses() const {
  auto objects = db_.LoadObjects(AIRCRAFT_CLASS_COLLECTION_NAME);
  std::vector<AircraftClass> result(objects.size());
  for (const auto &object : objects)
    result.push_back(db_converter.ToDataMapper<AircraftClass>(object));
  return result;
}
std::string StorageManager::LoadAircraftByIdAsJSON(const std::string &id) const {
  auto result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  return result ? db_converter.ToJSON(result.value().view()) : "null";
}
std::string StorageManager::LoadAircraftClassesAsJSON() const {
  auto objects = db_.LoadObjects(AIRCRAFT_CLASS_COLLECTION_NAME);
  return db_converter.ToJSON(objects);
}

}