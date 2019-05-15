#pragma once

#include <string>

#include "components/aircraft/aircraft_component.h"
#include "core/context_keeper.h"
#include "models/geo_point.h"
#include "services/json/json.h"

namespace hovertaxi {

class AircraftController : public ContextKeeper {
 public:
  explicit AircraftController(const Context &context)
      : ContextKeeper(context), aircraft_component_(context) {}

  std::string LoadAircraftInCircle(const std::pair<double, double> &center, int radius);
  std::string LoadCurrentOrderAircraft();
  std::string LoadAircraftClasses();
  std::string LoadNearestPads(const std::pair<double, double> &position);

 private:
  AircraftComponent aircraft_component_;
};

}