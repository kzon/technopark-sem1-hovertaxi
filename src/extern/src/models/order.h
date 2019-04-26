#pragma once

#include "mongo_data_mapper.h"
#include "i_json_convertable.h"

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
  OrderStatus status{OrderStatus::NEW};
  std::string from_pad_id, to_pad_id;
  std::string aircraft_class_id;
  std::string assigned_aircraft_id;
  std::string route_id;
  int price{};

  Order() = default;
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

  std::map<std::string, std::string> GetJsonFields() const override {
    auto fields = MongoDataMapper::GetJsonFields();
    fields["user_id"] = user_id;
    fields["status"] = StatusToString(status);
    fields["from_pad_id"] = from_pad_id;
    fields["to_pad_id"] = to_pad_id;
    fields["aircraft_class_id"] = aircraft_class_id;
    fields["assigned_aircraft_id"] = assigned_aircraft_id;
    fields["route_id"] = route_id;
    fields["price"] = std::to_string(price);
    return fields;
  }

 private:
  static std::string StatusToString(const OrderStatus &status) {
    switch (status) {
      case OrderStatus::NEW:return "NEW";
      case OrderStatus::PROCESSING:return "PROCESSING";
      case OrderStatus::AIRCRAFT_ASSIGNED:return "AIRCRAFT_ASSIGNED";
      case OrderStatus::ON_FLY:return "ON_FLY";
      case OrderStatus::FINISHED:return "FINISHED";
      case OrderStatus::CANCELED:return "CANCELED";
      case OrderStatus::PROCESS_TIMEOUT:return "PROCESS_TIMEOUT";
      default:return "null";
    }
  }
};

}