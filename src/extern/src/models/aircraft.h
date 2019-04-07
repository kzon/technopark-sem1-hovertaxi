#pragma once

#include <string>

#include "geo_point.h"

namespace hovertaxi {

struct Aircraft {
  std::string id;
  std::string model_id;
  std::string number;
  GeoPoint position;
  int speed;
  int direction;
  bool is_assigned;
};

}