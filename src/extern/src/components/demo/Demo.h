#pragma once

#include "models/DataMapper.h"

namespace components {

class Demo {
 public:
  static void CreateAircraftsRoutes();
  static void UpdateAircraftsPositions();
  static void AssignMoveToNearestPadRoute(const std::string &aircraft_id);
};

}