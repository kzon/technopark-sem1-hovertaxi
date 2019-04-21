#pragma once

#include "mongo_data_mapper.h"
#include "geo_point.h"

namespace hovertaxi {

class Pad : public MongoDataMapper {
 public:
  std::string name;
  GeoPoint position;
};

}