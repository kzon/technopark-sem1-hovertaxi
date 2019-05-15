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
                                                                            DataFilter &filter, size_t limit) const {
  mongocxx::options::find find_options;
  if (limit > 0)
    find_options.limit(limit);
  mongocxx::cursor cursor = GetCollection(collection).find(filter << bsoncxx::builder::stream::finalize, find_options);
  std::vector<std::unique_ptr<MongoDataObject>> result;
  for (const auto &view : cursor)
    result.push_back(std::unique_ptr<MongoDataObject>(new MongoDataObject(view)));
  return result;
}

mongocxx::collection MongoDataStorage::GetCollection(const std::string &name) const {
  return db_[name];
}

bool MongoDataStorage::InsertObject(const std::string &collection, const MongoDataObject &object) const {
  auto insert_result = GetCollection(collection).insert_one(object.view());
  return insert_result && insert_result.value().result().inserted_count() == 1;
}

bool MongoDataStorage::UpdateObject(const std::string &collection, const std::string &id, const MongoDataObject &object) const {
  auto update_result = GetCollection(collection).update_one(
      bsoncxx::builder::stream::document{} << "_id" << bsoncxx::oid(id) << bsoncxx::builder::stream::finalize,
      bsoncxx::builder::stream::document{}
          << "$set" << bsoncxx::builder::stream::open_document
          << bsoncxx::builder::stream::concatenate(object.view())
          << bsoncxx::builder::stream::close_document
          << bsoncxx::builder::stream::finalize
  );
  return update_result && update_result.value().result().modified_count() == 1;
}

}