#pragma once

#include <vector>

#include "models/Vehicle.cpp"

namespace components {

class Vehicle {
 public:
  static std::vector<models::Vehicle> LoadVehicles();
};

}