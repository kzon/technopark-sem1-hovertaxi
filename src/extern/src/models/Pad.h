#pragma once

#include "DataMapper.h"
#include "GeoPoint.h"

namespace models {

struct Pad : public DataMapper {
  std::string name;
  GeoPoint position;
};

}