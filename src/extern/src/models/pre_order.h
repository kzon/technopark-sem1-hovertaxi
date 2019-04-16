#pragma once

#include "data_mapper.h"
#include "route.h"

namespace hovertaxi {

struct PreOrder : public DataMapper {
  Route route;
  int price;
};

}