#pragma once

#include "mongo_data_mapper.h"

namespace hovertaxi {

enum OrderStatus {
  NEW,
  PROCESSING,
  AIRCRAFT_ASSIGNED,
  ON_FLY,
  FINISHED,
  CANCELED,
  PROCESS_TIMEOUT,
};

class Order : public MongoDataMapper {
 public:
  std::string user_id;
  OrderStatus status;
  std::string from_pad_id, to_pad_id;
  std::string aircraft_class_id;
  std::string assigned_aircraft_id;
  std::string route_id;
  int price;

  Order() {}
  explicit Order(const MongoDataObject &object) : MongoDataMapper(object) {
    auto data = object.data;
    this->user_id = data["user_id"].get_utf8().value.to_string();
    // this->status = ...
    this->from_pad_id = data["from_pad_id"].get_utf8().value.to_string();
    this->to_pad_id = data["to_pad_id"].get_utf8().value.to_string();
    this->aircraft_class_id = data["aircraft_class_id"].get_utf8().value.to_string();
    this->assigned_aircraft_id = data["assigned_aircraft_id"].get_utf8().value.to_string();
    this->route_id = data["route_id"].get_utf8().value.to_string();
    this->price = data["price"].get_int64().value;
  }

  static std::string GetSource() { return "order"; }
};

}