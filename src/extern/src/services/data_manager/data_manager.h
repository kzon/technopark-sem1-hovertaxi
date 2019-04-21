#pragma once

#include "models/aircraft.h"
#include "models/aircraft_class.h"
#include "models/pad.h"
#include "models/order.h"
#include "services/data_manager/data_storage/mongo_data_storage.h"

namespace hovertaxi {

class DataManager {
 public:
  static DataManager &GetInstance(const std::string &uri);

  core::optional<Aircraft> LoadAircraftById(const std::string &id) const;
  std::vector<Aircraft> LoadAircraftsInRadius(const GeoPoint &center, int radius) const;
  std::string LoadAircraftClassesAsJSON() const;
  void StoreAircraft(const Aircraft &aircraft) const;
  std::vector<Pad> LoadPadsInRadius(const GeoPoint &center, int radius) const;
  core::optional<Order> LoadOrderByUser(std::string user_id) const;
  void StoreOrder(const Order &order) const;
  size_t CountOrdersInRadius(const GeoPoint &center, int radius) const;

 private:
  explicit DataManager(const std::string &uri) : db_(uri) {}

  MongoDataStorage db_;
};

}