#include "data_manager.h"

namespace hovertaxi {

DataManager &hovertaxi::DataManager::GetInstance(const std::string &uri) {
  static DataManager instance(uri);
  return instance;
}

Optional<Aircraft> DataManager::LoadAircraftById(const std::string &id) const {
  return LoadObjectById<Aircraft>(id);
}

Optional<AircraftModel> DataManager::LoadAircraftModelById(const std::string &id) const {
  return LoadObjectById<AircraftModel>(id);
}

std::vector<std::unique_ptr<AircraftClass>> DataManager::LoadAircraftClasses() const {
  // @todo wtf
  std::vector<std::unique_ptr<MongoDataObject>> objects = db_.LoadObjects(AircraftClass::GetSource());
  std::vector<std::unique_ptr<AircraftClass>> result;
  result.reserve(objects.size());
  for (const auto &object : objects)
    result.push_back(std::unique_ptr<AircraftClass>(new AircraftClass(*object)));
  return result;
}

template<typename T>
Optional<T> DataManager::LoadObjectById(const std::string &id) const {
  Optional<MongoDataObject> result = db_.LoadObjectById(T::GetSource(), id);
  if (result) {
    T model(result.value());
    return Optional<T>(model);
  }
  return {};
}

}