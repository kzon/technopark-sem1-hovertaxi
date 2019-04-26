#pragma once

#include <string>
#include "models/i_json_convertable.h"

namespace hovertaxi {

class CancelOrderResult : public IJsonConvertable {
 public:
  std::string result;
  int cancel_price;

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["result"] = result;
    fields["cancel_price"] = std::to_string(cancel_price);
    return fields;
  }
};

}