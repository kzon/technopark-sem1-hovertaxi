#pragma once

#include <vector>

#include "../../model/Vehicle.h"

namespace component {

class Vehicle {
 public:
  std::vector<model::Vehicle> loadVehicles();
};

}