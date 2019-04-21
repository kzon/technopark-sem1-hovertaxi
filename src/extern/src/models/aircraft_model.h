#pragma once

#include "mongo_data_mapper.h"

namespace hovertaxi {

class AircraftModel : public DataMapper {
 public:
  std::string name;
  std::string class_id;
  int cruise_speed;
};

}