#include "ServiceLocator.h"

namespace services {

DataManager &ServiceLocator::GetDataManager() {
  return DataManager::GetInstance(db_uri_);
}

}