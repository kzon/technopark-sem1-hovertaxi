#pragma once

#include <vector>
#include "core/context_keeper.h"
#include "models/aircraft.h"
#include "models/aircraft_class.h"
#include "models/geo_point.h"
#include "models/pad.h"
#include "services/data_manager/data_manager.h"

namespace hovertaxi {

class AircraftComponent : public ContextKeeper {
 public:
  explicit AircraftComponent(const Context &context)
      : ContextKeeper(context), data_manager_(DataManager::GetInstance()) {}

  std::vector<std::unique_ptr<Aircraft>> LoadAircraftInCircle(const GeoPoint &center, int radius);
  Aircraft LoadCurrentOrderAircraft();
  std::vector<std::unique_ptr<AircraftClass>> LoadAircraftClasses();
  std::vector<std::unique_ptr<Pad>> LoadNearestPads(const GeoPoint &position);

 private:
  DataManager &data_manager_;
};

}