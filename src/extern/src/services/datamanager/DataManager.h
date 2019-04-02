#pragma once

#include <vector>
#include <iostream>
#include <sstream>

#include "services/datamanager/database/Database.h"
#include "models/Aircraft.h"
#include "models/AircraftClass.h"

namespace services {

class DataManager {
 public:
  DataManager(const DataManager &) = delete;
  DataManager &operator=(DataManager &) = delete;

  static DataManager &GetInstance(const std::string &uri);

  optional<models::Aircraft> LoadAircraftById(const std::string &id) const;
  std::string LoadAircraftByIdAsJSON(const std::string &id) const;

  std::vector<models::AircraftClass> LoadAircraftClasses() const;
  std::string LoadAircraftClassesAsJSON() const;
 private:
  explicit DataManager(const std::string &uri) : db_(uri) {}

  Database db_;

  const char* AIRCRAFT_COLLECTION_NAME = "aircraft";
  const char* AIRCRAFT_CLASS_COLLECTION_NAME = "aircraft_class";
};

}