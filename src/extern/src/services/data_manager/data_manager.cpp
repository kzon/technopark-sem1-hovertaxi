#include "data_manager.h"

namespace hovertaxi {

DataManager &DataManager::GetInstance() {
  static DataManager instance;
  return instance;
}

template<typename T>
Optional<T> DataManager::LoadObjectById(const std::string &id) const {
  Optional<MongoDataObject> result = db_.LoadObjectById(T::GetSource(), id);
  if (result) {
    T model(result.value());
    return Optional<T>(model);
  }
  return {};
}

template<typename T>
Optional<T> DataManager::LoadObject(DataFilter &filter) const {
  Optional<MongoDataObject> result = db_.LoadObject(T::GetSource(), filter);
  if (result) {
    T model(result.value());
    return Optional<T>(model);
  }
  return {};
}

template<typename T>
std::vector<std::unique_ptr<T>> DataManager::LoadObjects() const {
  DataFilter empty_filter;
  return LoadObjects<T>(empty_filter);
}

template<typename T>
std::vector<std::unique_ptr<T>> DataManager::LoadObjects(DataFilter &filter) const {
  std::vector<std::unique_ptr<MongoDataObject>> objects = db_.LoadObjects(T::GetSource(), filter);
  std::vector<std::unique_ptr<T>> result;
  result.reserve(objects.size());
  for (const auto &object : objects)
    result.push_back(std::unique_ptr<T>(new T(*object)));
  return result;
}

template<typename T>
bool DataManager::StoreObject(const T &object) const {
  if (object.id.empty())
    return db_.InsertObject(T::GetSource(), object.GetStorageObject());
  else
    return db_.UpdateObject(T::GetSource(), object.id, object.GetStorageObject());
}

Optional<Pad> DataManager::LoadPadById(const std::string &id) const {
  return LoadObjectById<Pad>(id);
}

std::vector<std::unique_ptr<AircraftClass>> DataManager::LoadAircraftClasses() const {
  return LoadObjects<AircraftClass>();
}

std::vector<std::unique_ptr<Aircraft>> DataManager::LoadAircraftsInRadius(const GeoPoint &center, int radius) const {
  DataFilter filter;
  DataFilterBuilder::GeoPointNear(filter, "position", center, radius);
  return LoadObjects<Aircraft>(filter);
}

std::vector<std::unique_ptr<Pad>> DataManager::LoadPadsInRadius(const GeoPoint &center, int radius) const {
  DataFilter filter;
  DataFilterBuilder::GeoPointNear(filter, "position", center, radius);
  return LoadObjects<Pad>(filter);
}

Optional<Order> DataManager::LoadOrderByUserAndFilter(const std::string &user_id, DataFilter &filter) const {
  DataFilterBuilder::StringEquals(filter, "user_id", user_id);
  return LoadObject<Order>(filter);
}

bool DataManager::StoreOrder(const Order &order) const {
  return StoreObject(order);
}

std::vector<std::unique_ptr<Order>> DataManager::LoadUnprocessedOrders() const {
  DataFilter filter;
  DataFilterBuilder::StringEquals(filter, "status", Order::STATUS_NEW);
  return LoadObjects<Order>(filter);
}

Optional<Aircraft> DataManager::LoadNearestFreeAircraft(const GeoPoint &position,
                                                        const std::string &aircraft_class_id) const {
  DataFilter filter;
  DataFilterBuilder::BoolEquals(filter, "is_assigned", false);
  DataFilterBuilder::GeoPointNear(filter, "position", position, 100000);

  auto aircraft_models = LoadAircraftModelsByAircraftClass(aircraft_class_id);
  std::vector<std::string> aircraft_models_ids(aircraft_models.size());
  for (const auto &aircraft_model : aircraft_models)
    aircraft_models_ids.push_back(aircraft_model->id);
  DataFilterBuilder::StringIn(filter, "model_id", aircraft_models_ids);

  return LoadObject<Aircraft>(filter);
}

std::vector<std::unique_ptr<AircraftModel>> DataManager::LoadAircraftModelsByAircraftClass(const std::string &aircraft_class_id) const {
  DataFilter filter;
  DataFilterBuilder::StringEquals(filter, "class_id", aircraft_class_id);
  return LoadObjects<AircraftModel>(filter);
}

bool DataManager::StoreAircraft(const Aircraft &aircraft) const {
  return StoreObject(aircraft);
}

Optional<Aircraft> DataManager::LoadAircraftById(const std::string &id) const {
  return LoadObjectById<Aircraft>(id);
}

Optional<AircraftClass> DataManager::LoadAircraftClassById(const std::string &id) const {
  return LoadObjectById<AircraftClass>(id);
}

Optional<AircraftModel> DataManager::LoadAircraftModelById(const std::string &id) const {
  return LoadObjectById<AircraftModel>(id);
}

}