#pragma once

#include <vector>
#include "models/i_json_convertable.h"
#include "models/geo_point.h"

namespace hovertaxi {

class JsonConverter {
 public:
  static std::string ToJSON(const IJsonConvertable &object);
};

}