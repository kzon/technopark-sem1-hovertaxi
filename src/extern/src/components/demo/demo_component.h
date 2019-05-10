#pragma once

#include "models/mongo_data_mapper.h"
#include "core/context_keeper.h"

namespace hovertaxi {

class DemoComponent : public ContextKeeper {
 public:
  explicit DemoComponent(const Context& context) : ContextKeeper(context) {}

  void CreateAircraftsRoutes();
  void UpdateAircraftsPositions();
  void AssignMoveToNearestPadRoute(const std::string &aircraft_id);
};

}