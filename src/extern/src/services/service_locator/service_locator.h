#pragma once

#include "services/data_manager/data_manager.h"

namespace hovertaxi {

class ServiceLocator {
 public:
  static DataManager &GetDataManager();

 private:
  static constexpr const char *db_uri_ = "mongodb://hovertaxi:hovertaxi@mongo:27017";
};

}