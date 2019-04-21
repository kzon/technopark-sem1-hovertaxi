#include "mongo_data_storage.h"

namespace hovertaxi {

std::vector<MongoDataObject> MongoDataStorage::LoadObjects(const std::string &collection) const {
  mongocxx::cursor cursor = GetCollection(collection).find({});
  std::vector<MongoDataObject> result;
  for (const auto &view : cursor)
    result.emplace_back(view);
  return result;
}

Optional<MongoDataObject> MongoDataStorage::LoadObjectById(const std::string &collection,
                                                           const std::string &id) const {
  bsoncxx::document::view_or_value filter = bsoncxx::builder::stream::document{}
      << "_id" << bsoncxx::oid(id)
      << bsoncxx::builder::stream::finalize;
  auto result = GetCollection(collection).find_one(filter);
  return {MongoDataObject(result.value())};
}

std::string MongoDataStorage::LoadObjectByIdAsJSON(const std::string &collection, const std::string &id) const {
  auto object = LoadObjectById(collection, id);
  return object ? ToJSON(object.value()) : "null";
}

std::string MongoDataStorage::LoadObjectsAsJSON(const std::string &collection) const {
  return ToJSON(LoadObjects(collection));
}

mongocxx::collection MongoDataStorage::GetCollection(const std::string &name) const {
  return db_[name];
}

std::string MongoDataStorage::ToJSON(const MongoDataObject &object) const {
  return bsoncxx::to_json(object.data);
}

std::string MongoDataStorage::ToJSON(const std::vector<MongoDataObject> &objects) const {
  std::ostringstream result;
  bool is_first = true;
  result << '[';
  for (const auto &object : objects) {
    if (!is_first)
      result << ',';
    result << ToJSON(object);
    is_first = false;
  }
  result << ']';
  return result.str();
}

}