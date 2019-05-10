#pragma once

#include "mongo_data_mapper.h"
#include "route.h"
#include "i_json_convertable.h"
#include "services/json/json.h"

namespace hovertaxi {

class PreOrder : public IJsonConvertable {
 public:
  Route route;
  int price{};

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["route"] = JSON::ToJSON(route);
    fields["price"] = std::to_string(price);
    return fields;
  }
};

}