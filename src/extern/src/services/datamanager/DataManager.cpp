#include "DataManager.h"

namespace services {

DataManager &DataManager::GetInstance(const std::string &uri) {
  static DataManager instance(uri);
  return instance;
}

optional<models::Aircraft> DataManager::LoadAircraftById(const std::string &id) const {
  auto result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  if (result) {
    models::Aircraft aircraft = db_.ConvertAircraftToModel(result.value());
    return optional<models::Aircraft>(aircraft);
  }
  return {};
}

std::string DataManager::LoadAircraftByIdAsJSON(const std::string &id) const {
  auto result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  return result ? db_.ToJSON(result.value()) : "null";
}

}