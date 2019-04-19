#pragma once

#include "services/storage_manager/storage_manager.h"

namespace hovertaxi {

class ServiceLocator {
 public:
  static StorageManager &GetDataManager();

 private:
  static constexpr const char* db_uri_ = "mongodb://hovertaxi:hovertaxi@mongo:27017";
};

}