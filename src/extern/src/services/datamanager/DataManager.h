#pragma once

#include <vector>

#include "services/datamanager/database/Database.h"
#include "models/Aircraft.h"

namespace services {

class DataManager {
 public:
  DataManager(const DataManager &) = delete;
  DataManager &operator=(DataManager &) = delete;

  static DataManager &GetInstance(const std::string &uri);

  optional<models::Aircraft> LoadAircraftById(const std::string &id) const;
  std::string LoadAircraftByIdAsJSON(const std::string &id) const;
 private:
  explicit DataManager(const std::string &uri) : db_(uri) {}

  Database db_;

  const char* AIRCRAFT_COLLECTION_NAME = "aircraft";
};

}