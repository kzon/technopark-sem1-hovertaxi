#include "service_locator.h"

namespace hovertaxi {

DataManager &ServiceLocator::GetDataManager() {
  return DataManager::GetInstance(db_uri_);
}

}