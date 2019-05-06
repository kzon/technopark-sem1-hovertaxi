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
  int price{};

  Order() = default;
  explicit Order(const MongoDataObject &object) : MongoDataMapper(object) {
    this->user_id = object.view()["user_id"].get_utf8().value.to_string();
    // this->status = ...
    this->from_pad_id = object.view()["from_pad_id"].get_utf8().value.to_string();
    this->to_pad_id = object.view()["to_pad_id"].get_utf8().value.to_string();
    this->aircraft_class_id = object.view()["aircraft_class_id"].get_utf8().value.to_string();
    this->assigned_aircraft_id = object.view()["assigned_aircraft_id"].get_utf8().value.to_string();
    this->route_id = object.view()["route_id"].get_utf8().value.to_string();
    this->price = object.view()["price"].get_int32().value;
  }

  static std::string GetSource() { return "order"; }
};

}