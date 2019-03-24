#include "Vehicle.h"

namespace components {

std::vector<models::Vehicle> Vehicle::LoadVehicles() {
  std::vector<models::Vehicle> vehicles;
  models::Vehicle v1{"Boeing TDA", models::GeoPoint{53.1235, 58.2345}};
  vehicles.push_back(v1);
  return vehicles;
}

}