#pragma once

#include "models/DataMapper.h"
#include "core/context_keeper.h"

namespace components {

class Demo : public ContextKeeper {
 public:
  static void CreateAircraftsRoutes();
  static void UpdateAircraftsPositions();
  static void AssignMoveToNearestPadRoute(const std::string &aircraft_id);
};

}