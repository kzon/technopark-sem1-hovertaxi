#pragma once

#include "models/mongo_data_mapper.h"
#include "core/context_keeper.h"

namespace hovertaxi {

class DemoComponent : public ContextKeeper {
 public:
  static void CreateAircraftsRoutes();
  static void UpdateAircraftsPositions();
  static void AssignMoveToNearestPadRoute(const std::string &aircraft_id);
};

}