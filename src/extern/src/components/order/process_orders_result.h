#pragma once

#include <string>
#include "models/i_json_convertable.h"

namespace hovertaxi {

struct ProcessOrdersResult : public IJsonConvertable {
  size_t orders_processed{};
  size_t aircrafts_assigned{};
  size_t no_suitable_aircraft{};

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["orders_processed"] = std::to_string(orders_processed);
    fields["aircrafts_assigned"] = std::to_string(aircrafts_assigned);
    fields["no_suitable_aircraft"] = std::to_string(no_suitable_aircraft);
    return fields;
  }
};

}