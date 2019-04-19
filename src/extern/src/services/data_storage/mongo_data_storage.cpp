
#include "mongo_data_storage.h"

namespace hovertaxi {

std::vector<View> MongoDataStorage::LoadObjects(const std::string &collection) const {
  mongocxx::cursor cursor = GetCollection(collection).find({});
  std::vector<View> result(cursor.begin(), cursor.end());
  return result;
}

core::optional<Value> MongoDataStorage::LoadObjectById(const std::string &collection, const std::string &id) const {
  bsoncxx::document::view_or_value filter = bsoncxx::builder::stream::document{}
      << "_id" << bsoncxx::oid(id)
      << bsoncxx::builder::stream::finalize;
  auto result = GetCollection(collection).find_one(filter);
  return result;
}

mongocxx::collection MongoDataStorage::GetCollection(const std::string &name) const {
  return db_[name];
}

}