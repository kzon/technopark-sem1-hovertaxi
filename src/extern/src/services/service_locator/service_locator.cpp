#include "service_locator.h"

namespace hovertaxi {

StorageManager &ServiceLocator::GetDataManager() {
  return StorageManager::GetInstance(db_uri_);
}

}