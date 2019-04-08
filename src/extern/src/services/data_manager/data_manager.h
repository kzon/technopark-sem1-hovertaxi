#pragma once

#include <vector>
#include <iostream>
#include <sstream>

#include "services/data_manager/database/database.h"
#include "models/aircraft.h"
#include "models/aircraft_class.h"

namespace hovertaxi {

class DataManager {
 public:
  DataManager(const DataManager &) = delete;
  DataManager &operator=(DataManager &) = delete;

  static DataManager &GetInstance(const std::string &uri);

  optional<Aircraft> LoadAircraftById(const std::string &id) const;
  std::string LoadAircraftByIdAsJSON(const std::string &id) const;

  std::vector<AircraftClass> LoadAircraftClasses() const;
  std::string LoadAircraftClassesAsJSON() const;
 private:
  explicit DataManager(const std::string &uri) : db_(uri) {}

  Database db_;

  const char* AIRCRAFT_COLLECTION_NAME = "aircraft";
  const char* AIRCRAFT_CLASS_COLLECTION_NAME = "aircraft_class";
};

}