#pragma once

#include "data_mapper.h"

namespace hovertaxi {

struct AircraftClass : public DataMapper {
  std::string name;
  int min_range;
  int max_range;
};

}