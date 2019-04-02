#include "DataManager.h"

namespace services {

DataManager &DataManager::GetInstance(const std::string &uri) {
  static DataManager instance(uri);
  return instance;
}

optional<models::Aircraft> DataManager::LoadAircraftById(const std::string &id) const {
  auto result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  if (result) {
    models::Aircraft aircraft = db_.ConvertAircraftToModel(result.value().view());
    return optional<models::Aircraft>(aircraft);
  }
  return {};
}

std::string DataManager::LoadAircraftByIdAsJSON(const std::string &id) const {
  auto result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  return result ? db_.ToJSON(result.value().view()) : "null";
}

std::vector<models::AircraftClass> DataManager::LoadAircraftClasses() const {
  auto objects = db_.LoadObjects(AIRCRAFT_CLASS_COLLECTION_NAME);
  std::vector<models::AircraftClass> result(objects.size());
  for (const auto &object : objects)
    result.push_back(db_.ConvertAircraftClassToModel(object));
  return result;
}

std::string DataManager::LoadAircraftClassesAsJSON() const {
  auto objects = db_.LoadObjects(AIRCRAFT_CLASS_COLLECTION_NAME);
  std::ostringstream result;
  bool is_first = true;
  result << '[';
  for (const auto &object : objects) {
    if (!is_first)
      result << ',';
    result << db_.ToJSON(object);
    is_first = false;
  }
  result << ']';
  return result.str();
}

}