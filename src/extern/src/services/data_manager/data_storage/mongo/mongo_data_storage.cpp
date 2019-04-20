#include "mongo_data_storage.h"

namespace hovertaxi {

std::vector<AbstractDataObject> MongoDataStorage::LoadObjects(const std::string &collection) const {
  mongocxx::cursor cursor = GetCollection(collection).find({});
  std::vector<AbstractDataObject> result;
  std::transform(cursor.begin(), cursor.end(), result.begin(), [](bsoncxx::document::value value) {
    return MongoDataObject(value);
  });
  return result;
}

Optional<AbstractDataObject> MongoDataStorage::LoadObjectById(const std::string &collection,
                                                                 const std::string &id) const {
  bsoncxx::document::view_or_value filter = bsoncxx::builder::stream::document{}
      << "_id" << bsoncxx::oid(id)
      << bsoncxx::builder::stream::finalize;
  auto result = GetCollection(collection).find_one(filter);
  return {MongoDataObject(result.value())};
}

mongocxx::collection MongoDataStorage::GetCollection(const std::string &name) const {
  return db_[name];
}

}