#pragma once

#include "mongo_data_mapper.h"

namespace hovertaxi {

class Order : public MongoDataMapper {
 public:
  std::string user_id;
  std::string status;
  std::string from_pad_id, to_pad_id;
  std::string aircraft_class_id;
  std::string assigned_aircraft_id;
  std::string route_id;
  int price{};

  static constexpr const char *STATUS_NEW = "new";
  static constexpr const char *STATUS_PROCESSING = "processing";
  static constexpr const char *STATUS_AIRCRAFT_ASSIGNED = "aircraft_assigned";
  static constexpr const char *STATUS_ON_FLY = "on_fly";
  static constexpr const char *STATUS_FINISHED = "finished";
  static constexpr const char *STATUS_CANCELED = "canceled";
  static constexpr const char *STATUS_PROCESSING_TIMEOUT = "processing_timeout";

  Order() = default;
  explicit Order(const MongoDataObject &object) : MongoDataMapper(object) {
    user_id = object.view()["user_id"].get_utf8().value.to_string();
    status = object.view()["status"].get_utf8().value.to_string();
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
    fields["status"] = status;
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
        << "status" << status
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