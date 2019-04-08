#pragma once

#include "data_mapper.h"

namespace hovertaxi {

struct AircraftModel : public DataMapper {
  std::string name;
  std::string class_id;
  int cruise_speed;
};

}