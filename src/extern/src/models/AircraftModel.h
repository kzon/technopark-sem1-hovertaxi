#pragma once

#include "DataMapper.h"

namespace models {

struct AircraftModel : public DataMapper {
  std::string class_id;
  std::string name;
  int cruise_speed;
};

}