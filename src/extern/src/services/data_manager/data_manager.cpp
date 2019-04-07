#include "data_manager.h"

namespace hovertaxi {

DataManager &DataManager::GetInstance(const std::string &uri) {
  static DataManager instance(uri);
  return instance;
}

optional<Aircraft> DataManager::LoadAircraftById(const std::string &id) const {
  auto result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  if (result) {
    Aircraft aircraft = db_.ConvertAircraftToModel(result.value().view());
    return optional<Aircraft>(aircraft);
  }
  return {};
}

std::string DataManager::LoadAircraftByIdAsJSON(const std::string &id) const {
  auto result = db_.LoadObjectById(AIRCRAFT_COLLECTION_NAME, id);
  return result ? db_.ToJSON(result.value().view()) : "null";
}

std::vector<AircraftClass> DataManager::LoadAircraftClasses() const {
  auto objects = db_.LoadObjects(AIRCRAFT_CLASS_COLLECTION_NAME);
  std::vector<AircraftClass> result(objects.size());
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