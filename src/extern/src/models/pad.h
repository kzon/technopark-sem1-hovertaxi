#pragma once

#include "data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

struct Pad : public DataMapper {
  std::string name;
  GeoPoint position;
};

}