#pragma once

#include "DataMapper.h"
#include "Route.h"

namespace models {

struct PreOrder : public DataMapper {
  Route route;
  int price;
};

}