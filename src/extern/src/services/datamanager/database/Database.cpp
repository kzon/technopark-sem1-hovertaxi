#include "Database.h"

namespace services {

optional<bsoncxx::document::value> Database::LoadObjectById(
    const std::string &collection,
    const std::string &id
) const {
  bsoncxx::document::view_or_value filter = bsoncxx::builder::stream::document{}
      << "_id" << bsoncxx::oid(id)
      << bsoncxx::builder::stream::finalize;
  auto result = GetCollection(collection).find_one(filter);
  return result;
}

mongocxx::collection Database::GetCollection(const std::string &name) const {
  return db_[name];
}

std::string Database::ToJSON(const bsoncxx::document::value &object) const {
  return bsoncxx::to_json(object.view());
}

models::Aircraft Database::ConvertAircraftToModel(bsoncxx::document::value &document) const {
  auto view = document.view();
  models::Aircraft aircraft;
  aircraft.id = view["_id"].get_oid().value.to_string();
  aircraft.model = view["model"].get_utf8().value.to_string();
  return aircraft;
}

}