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

std::vector<std::unique_ptr<AircraftClass>> DataManager::LoadAircraftClasses() const {
  std::vector<std::unique_ptr<MongoDataObject>> objects = db_.LoadObjects(AircraftClass::GetSource());
  std::vector<std::unique_ptr<AircraftClass>> result;
  result.reserve(objects.size());
  for (const auto &object : objects)
    result.push_back(std::unique_ptr<AircraftClass>(new AircraftClass(*object)));
  return result;
}

}