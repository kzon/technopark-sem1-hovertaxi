#pragma once

#include <vector>

#include "models/Vehicle.cpp"

namespace components {

class Vehicle {
 public:
  std::vector<models::Vehicle> LoadVehicles();
};

}