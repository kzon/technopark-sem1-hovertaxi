#pragma once

#include "mongo_data_converter.h"

namespace hovertaxi {

template<>
Aircraft MongoDataConverter::ToDataMapper<Aircraft>(const View &view) const {
  Aircraft aircraft;
  aircraft.id = view["_id"].get_oid().value.to_string();
  aircraft.model_id = view["model_id"].get_oid().value.to_string();
  return aircraft;
}

template<>
AircraftModel MongoDataConverter::ToDataMapper<AircraftModel>(const View &view) const {
  AircraftModel model;
  return model;
}

template<>
AircraftClass MongoDataConverter::ToDataMapper<AircraftClass>(const View &view) const {
  AircraftClass aircraft_class;
  aircraft_class.id = view["_id"].get_oid().value.to_string();
  aircraft_class.name = view["name"].get_utf8().value.to_string();
  aircraft_class.max_range = view["max_range"].get_int32().value;
  aircraft_class.min_range = view["min_range"].get_int32().value;
  return aircraft_class;
}

template<>
Order MongoDataConverter::ToDataMapper<Order>(const View &view) const {
  Order order;
  return order;
}

template<>
Route MongoDataConverter::ToDataMapper<Route>(const View &view) const {
  Route route;
  return route;
}

template<>
Pad MongoDataConverter::ToDataMapper<Pad>(const View &view) const {
  Pad pad;
  return pad;
}

std::string MongoDataConverter::ToJSON(const View &obj) const {
  return bsoncxx::to_json(obj);
}
std::string MongoDataConverter::ToJSON(const std::vector<View> &objects) const {
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