#include "database.h"

namespace hovertaxi {

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

std::vector<bsoncxx::document::view> Database::LoadObjects(const std::string &collection) const {
  mongocxx::cursor cursor = GetCollection(collection).find({});
  std::vector<bsoncxx::document::view> result(cursor.begin(), cursor.end());
  return result;
}

mongocxx::collection Database::GetCollection(const std::string &name) const {
  return db_[name];
}

std::string Database::ToJSON(const bsoncxx::document::view &view) const {
  return bsoncxx::to_json(view);
}

Aircraft Database::ConvertAircraftToModel(const bsoncxx::document::view &view) const {
  Aircraft aircraft;
  aircraft.id = view["_id"].get_oid().value.to_string();
  aircraft.model_id = view["model_id"].get_oid().value.to_string();
  return aircraft;
}

AircraftClass Database::ConvertAircraftClassToModel(const bsoncxx::document::view &view) const {
  AircraftClass aircraft_class;
  aircraft_class.id = view["_id"].get_oid().value.to_string();
  aircraft_class.name = view["name"].get_utf8().value.to_string();
  aircraft_class.max_range = view["max_range"].get_int32().value;
  aircraft_class.min_range = view["min_range"].get_int32().value;
  return aircraft_class;
}

}