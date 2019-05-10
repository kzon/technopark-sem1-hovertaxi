#include "mongo_data_storage.h"

namespace hovertaxi {

MongoDataStorage &MongoDataStorage::GetInstance() {
  static MongoDataStorage instance("mongodb://hovertaxi:hovertaxi@mongo:27017");
  return instance;
}

Optional<MongoDataObject> MongoDataStorage::LoadObjectById(const std::string &collection,
                                                           const std::string &id) const {
  auto result = GetCollection(collection).find_one(
      bsoncxx::builder::stream::document{} << "_id" << bsoncxx::oid(id) << bsoncxx::builder::stream::finalize
  );
  if (result)
    return {MongoDataObject(std::move(result.value()))};
  return {};
}

Optional<MongoDataObject> MongoDataStorage::LoadObject(const std::string &collection, DataFilter &filter) const {
  auto result = GetCollection(collection).find_one(filter << bsoncxx::builder::stream::finalize);
  if (result)
    return {MongoDataObject(std::move(result.value()))};
  return {};
}

std::vector<std::unique_ptr<MongoDataObject>> MongoDataStorage::LoadObjects(const std::string &collection,
                                                                            DataFilter &filter) const {
  mongocxx::cursor cursor = GetCollection(collection).find(filter << bsoncxx::builder::stream::finalize);
  std::vector<std::unique_ptr<MongoDataObject>> result;
  for (const auto &view : cursor)
    result.push_back(std::unique_ptr<MongoDataObject>(new MongoDataObject(view)));
  return result;
}

mongocxx::collection MongoDataStorage::GetCollection(const std::string &name) const {
  return db_[name];
}

bool MongoDataStorage::StoreObject(const std::string &collection, const MongoDataObject &object) const {
  bsoncxx::stdx::optional<mongocxx::result::insert_one>
      insert_result = GetCollection(collection).insert_one(object.view());
  return insert_result && insert_result.value().result().inserted_count() == 1;
}

}