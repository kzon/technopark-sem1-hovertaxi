#include "data_manager.h"

namespace hovertaxi {

DataManager &hovertaxi::DataManager::GetInstance(const std::string &uri) {
  static DataManager instance(uri);
  return instance;
}

core::optional<Aircraft> DataManager::LoadAircraftById(const std::string &id) const {
  Optional<MongoDataObject> result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  if (result) {
    Aircraft aircraft(result.value());
    return core::optional<Aircraft>(aircraft);
  }
  return {};
}

std::vector<AircraftClass> DataManager::LoadAircraftClasses() const {
  auto objects = db_.LoadObjects(AIRCRAFT_CLASS_COLLECTION_NAME);
  std::vector<AircraftClass> result(objects.size());
  for (const auto &object : objects)
    result.emplace_back(object);
  return result;
}

std::string DataManager::LoadAircraftByIdAsJSON(const std::string &id) const {
  auto result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  return result ? db_converter_.ToJSON(MongoDataObject(result.value())) : "null";
}

std::string DataManager::LoadAircraftClassesAsJSON() const {
  auto objects = db_.LoadObjects(AIRCRAFT_CLASS_COLLECTION_NAME);
  return db_converter_.ToJSON(objects);
}

}