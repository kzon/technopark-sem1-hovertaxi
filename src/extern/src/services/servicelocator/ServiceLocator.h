#pragma once

#include "services/datamanager/DataManager.h"

namespace services {

class ServiceLocator {
 public:
  static DataManager &GetDataManager();

 private:
  static constexpr const char* db_uri_ = "mongodb://hovertaxi:hovertaxi@mongo:27017";
};

}