#pragma once

#include <ctime>

#include "mongo_data_mapper.h"
#include "route.h"
#include "i_json_convertable.h"
#include "services/json/json.h"

namespace hovertaxi {

class PreOrder : public MongoDataMapper {
 public:
  std::string user_id;
  int price{};
  Route route;

  PreOrder() = default;
  explicit PreOrder(const MongoDataObject &object) : MongoDataMapper(object) {
    user_id = object.view()["user_id"].get_utf8().value.to_string();
    price = object.view()["price"].get_int32();
  }

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["user_id"] = user_id;
    fields["price"] = std::to_string(price);
    fields["route"] = JSON::ToJSON(route, true);
    return fields;
  }

  static std::string GetSource() { return "pre_order"; }

  MongoDataObject GetStorageObject() const override {
    auto object = bsoncxx::builder::stream::document{}
        << "user_id" << user_id
        << "price" << price
        << bsoncxx::builder::stream::finalize;
    return object;
  }

};

}