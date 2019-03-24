#pragma once

#include <string>
#include "GeoPoint.cpp"

namespace models {

struct Vehicle {
  std::string model;
  models::GeoPoint position;
};

}