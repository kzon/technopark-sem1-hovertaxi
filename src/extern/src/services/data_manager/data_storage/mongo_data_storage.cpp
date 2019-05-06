#include "mongo_data_storage.h"

namespace hovertaxi {

std::vector<std::unique_ptr<MongoDataObject>> MongoDataStorage::LoadObjects(const std::string &collection) const {
  mongocxx::cursor cursor = GetCollection(collection).find({});
  std::vector<std::unique_ptr<MongoDataObject>> result;
  for (const auto &view : cursor)
    result.push_back(std::unique_ptr<MongoDataObject>(new MongoDataObject(view)));
  return result;
}

Optional<MongoDataObject> MongoDataStorage::LoadObjectById(const std::string &collection,
                                                           const std::string &id) const {
  bsoncxx::stdx::optional<bsoncxx::document::value> result = GetCollection(collection).find_one(
      bsoncxx::builder::stream::document{} << "_id" << bsoncxx::oid(id) << bsoncxx::builder::stream::finalize
  );
  if (result)
    return {MongoDataObject(std::move(result.value()))};
  return {};
}

mongocxx::collection MongoDataStorage::GetCollection(const std::string &name) const {
  return db_[name];
}

}