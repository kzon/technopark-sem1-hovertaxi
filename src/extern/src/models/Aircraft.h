#pragma once

#include <string>

#include "DataMapper.h"
#include "GeoPoint.h"

namespace models {

struct Aircraft : public DataMapper {
  std::string model_id;
  std::string number;
  GeoPoint position;
  int speed;
  int direction;
  bool is_assigned;
};

}