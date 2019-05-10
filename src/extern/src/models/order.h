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
    user_id = object.view()["user_id"].get_utf8().value.to_string();
    // status = ...
    from_pad_id = object.view()["from_pad_id"].get_utf8().value.to_string();
    to_pad_id = object.view()["to_pad_id"].get_utf8().value.to_string();
    aircraft_class_id = object.view()["aircraft_class_id"].get_utf8().value.to_string();
    assigned_aircraft_id = object.view()["assigned_aircraft_id"].get_utf8().value.to_string();
    route_id = object.view()["route_id"].get_utf8().value.to_string();
    price = object.view()["price"].get_int32().value;
  }

  static std::string GetSource() { return "order"; }

  std::map<std::string, std::string> GetJsonFields() const override {
    auto fields = MongoDataMapper::GetJsonFields();
    fields["user_id"] = user_id;
    //fields["status"] = status;
    fields["from_pad_id"] = from_pad_id;
    fields["to_pad_id"] = to_pad_id;
    fields["aircraft_class_id"] = aircraft_class_id;
    fields["assigned_aircraft_id"] = assigned_aircraft_id;
    fields["route_id"] = route_id;
    fields["price"] = std::to_string(price);
    return fields;
  }

  MongoDataObject GetStorageObject() const override {
    auto object = bsoncxx::builder::stream::document{}
        << "user_id" << user_id
        << "from_pad_id" << from_pad_id
        << "to_pad_id" << to_pad_id
        << "aircraft_class_id" << aircraft_class_id
        << "assigned_aircraft_id" << assigned_aircraft_id
        << "route_id" << route_id
        << "price" << price
        << bsoncxx::builder::stream::finalize;
    return object;
  }
};

}