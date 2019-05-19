#pragma once

#include <memory>
#include <string>
#include "core/macros.h"
#include "models/aircraft.h"
#include "models/aircraft_model.h"
#include "models/aircraft_class.h"
#include "models/pad.h"
#include "models/order.h"
#include "services/data_manager/data_storage/mongo_data_storage.h"
#include "services/data_manager/data_storage/data_filter.h"
#include "services/data_manager/data_storage/data_filter_builder.h"

namespace hovertaxi {

class DataManager {
 public:
  DISALLOW_COPY_AND_ASSIGN(DataManager);

  static DataManager &GetInstance();

  std::vector<std::unique_ptr<Aircraft>> LoadAircraftsInRadius(const GeoPoint &center, int radius) const;
  Optional<Aircraft> LoadNearestFreeAircraft(const GeoPoint &position, const std::string &aircraft_class_id) const;
  bool StoreAircraft(const Aircraft &aircraft) const;

  std::vector<std::unique_ptr<AircraftClass>> LoadAircraftClasses() const;

  std::vector<std::unique_ptr<AircraftModel>> LoadAircraftModelsByAircraftClass(const std::string &aircraft_class_id) const;

  Optional<Pad> LoadPadById(const std::string &id) const;
  std::vector<std::unique_ptr<Pad>> LoadPadsInRadius(const GeoPoint &center, int radius) const;

  std::vector<std::unique_ptr<Order>> LoadUnprocessedOrders() const;
  Optional<Order> LoadOrderByUserAndFilter(const std::string &user_id, DataFilter &filter) const;
  bool StoreOrder(const Order &order) const;
  size_t CountOrdersInRadius(const GeoPoint &center, int radius) const;

 private:
  explicit DataManager() : db_(MongoDataStorage::GetInstance()) {}

  template<typename T>
  Optional<T> LoadObjectById(const std::string &id) const;

  template<typename T>
  Optional<T> LoadObject(DataFilter &filter) const;

  template<typename T>
  std::vector<std::unique_ptr<T>> LoadObjects() const;

  template<typename T>
  std::vector<std::unique_ptr<T>> LoadObjects(DataFilter &filter) const;

  template<typename T>
  bool StoreObject(const T &object) const;

  MongoDataStorage &db_;
};

}