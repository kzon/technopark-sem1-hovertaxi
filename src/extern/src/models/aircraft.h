#pragma once

#include <string>

#include "data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

struct Aircraft : public DataMapper {
  std::string model_id;
  std::string number;
  GeoPoint position;
  int speed;
  int direction;
  bool is_assigned;
};

}