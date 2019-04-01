#pragma once

#include <string>
#include "GeoPoint2D.h"

namespace models {

struct Aircraft {
  std::string model;
  models::GeoPoint2D position;
  std::string id;
};

}