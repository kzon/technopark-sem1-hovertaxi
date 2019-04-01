#include "DataManager.h"

namespace services {

DataManager &DataManager::GetInstance(const std::string &uri) {
  static DataManager instance(uri);
  return instance;
}

optional<models::Aircraft> DataManager::LoadAircraftById(std::string id) const {
  bsoncxx::document::view_or_value filter = bsoncxx::builder::stream::document{}
      << "_id" << bsoncxx::oid(id)
      << bsoncxx::builder::stream::finalize;
  bsoncxx::stdx::optional<bsoncxx::document::value> result =
      GetAircraftCollection().find_one(filter);
  if (result) {
    models::Aircraft aircraft = ConvertAircraftToModel(result.value());
    return optional<models::Aircraft>(aircraft);
  }
  return {};
}

mongocxx::database DataManager::GetDatabase() const {
  return client_[database_name_];
}

mongocxx::collection DataManager::GetAircraftCollection() const {
  return GetDatabase()["aircraft"];
}

models::Aircraft DataManager::ConvertAircraftToModel(bsoncxx::document::value &aircraft) const {
  bsoncxx::document::view view = aircraft.view();
  models::Aircraft result;
  result.id = view["_id"].get_oid().value.to_string();
  result.model = view["model"].get_utf8().value.to_string();
  return result;
}

}