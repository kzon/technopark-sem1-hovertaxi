#pragma once

#include "DataMapper.h"

namespace models {

struct AircraftModel : public DataMapper {
  std::string name;
  std::string class_id;
  int cruise_speed;
};

}