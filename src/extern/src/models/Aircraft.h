#pragma once

#include <string>

#include "GeoPoint.h"

namespace models {

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