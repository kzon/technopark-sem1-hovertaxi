#include <string>

#include "core/context_keeper.h"
#include "models/geo_point.h"

namespace hovertaxi {

class AircraftController : public ContextKeeper {
 public:
  explicit AircraftController(const Context &context) : ContextKeeper(context) {}

  std::string LoadAircraftInCircle(const std::pair<double, double> &center, int radius);
  std::string LoadCurrentOrderAircraft();
  std::string LoadAircraftClasses();
  std::string LoadNearestPads(const std::pair<double, double> &position);
};

}