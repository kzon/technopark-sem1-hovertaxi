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
  time_t date{};
  Route route;
  int price{};

  PreOrder() = default;
  explicit PreOrder(const MongoDataObject &object) : MongoDataMapper(object) {
    user_id = object.view()["user_id"].get_utf8().value.to_string();
    price = object.view()["price"].get_int32();
  }

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["user_id"] = user_id;
    fields["route"] = JSON::ToJSON(route, true);
    fields["price"] = std::to_string(price);
    auto date_str = std::string(ctime(&date));
    date_str.erase(date_str.length() - 1, 1); //remove new line
    fields["date"] = date_str;
    return fields;
  }

  static std::string GetSource() { return "pre_order"; }

  MongoDataObject GetStorageObject() const override {
    auto object = bsoncxx::builder::stream::document{}
        << "user_id" << user_id
        << "date" << date
        << "price" << price
        << bsoncxx::builder::stream::finalize;
    return object;
  }

};

}