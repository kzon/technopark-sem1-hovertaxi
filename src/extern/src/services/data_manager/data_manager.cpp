#include "data_manager.h"

namespace hovertaxi {

DataManager &hovertaxi::DataManager::GetInstance(const std::string &uri) {
  static DataManager instance(uri);
  return instance;
}

Optional<Aircraft> DataManager::LoadAircraftById(const std::string &id) const {
  Optional<MongoDataObject> result = db_.LoadObjectById(Aircraft::GetSource(), id);
  if (result) {
    Aircraft aircraft(result.value());
    return Optional<Aircraft>(aircraft);
  }
  return {};
}

Optional<AircraftModel> DataManager::LoadAircraftModelById(const std::string &id) const {
  Optional<MongoDataObject> result = db_.LoadObjectById(AircraftModel::GetSource(), id);
  if (result) {
    AircraftModel aircraft_model(result.value());
    return Optional<AircraftModel>(aircraft_model);
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