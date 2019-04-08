#pragma once

#include "DataMapper.h"

namespace models {

struct AircraftClass : public DataMapper {
  std::string name;
  int min_range;
  int max_range;
};

}