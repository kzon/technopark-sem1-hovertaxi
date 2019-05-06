#pragma once

#include <memory>
#include "models/aircraft.h"
#include "models/aircraft_model.h"
#include "models/aircraft_class.h"
#include "models/pad.h"
#include "models/order.h"
#include "services/data_manager/data_storage/mongo_data_storage.h"
#include "services/data_manager/data_storage/data_filter.h"
#include "services/data_manager/data_storage/data_filter_condition.h"

namespace hovertaxi {

class DataManager {
 public:
  static DataManager &GetInstance(const std::string &uri);

  Optional<Aircraft> LoadAircraftById(const std::string &id) const;
  Optional<AircraftModel> LoadAircraftModelById(const std::string &id) const;
  std::vector<std::unique_ptr<Aircraft>> LoadAircraftsInRadius(const GeoPoint &center, int radius) const;
  std::vector<std::unique_ptr<AircraftClass>> LoadAircraftClasses() const;
  void StoreAircraft(const Aircraft &aircraft) const;
  std::vector<std::unique_ptr<Pad>> LoadPadsInRadius(const GeoPoint &center, int radius) const;
  Optional<Order> LoadOrderByUser(std::string user_id) const;
  void StoreOrder(const Order &order) const;
  size_t CountOrdersInRadius(const GeoPoint &center, int radius) const;

 private:
  explicit DataManager(const std::string &uri) : db_(uri) {}

  template<typename T>
  Optional<T> LoadObjectById(const std::string &id) const;

  template<typename T>
  std::vector<std::unique_ptr<T>> LoadObjects() const;
  template<typename T>
  std::vector<std::unique_ptr<T>> LoadObjects(DataFilter &filter) const;

  MongoDataStorage db_;
};

}