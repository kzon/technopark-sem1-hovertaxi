#pragma once

#include "mongo_data_mapper.h"
#include "route.h"

namespace hovertaxi {

class PreOrder : public MongoDataMapper {
 public:
  Route route;
  int price;
};

}