#include <string>

#include "controllers/base/BaseController.h"
#include "core/context_keeper.h"
#include "models/GeoPoint.h"

namespace controllers {

class Aircraft : public ContextKeeper {
 public:
  explicit Aircraft(const models::Context &context) : ContextKeeper(context) {}

  std::string LoadAircraftInCircle(const std::pair<double, double> &center, int radius);
  std::string LoadCurrentOrderAircraft();
  std::string LoadAircraftClasses();
  std::string LoadNearestPads(const std::pair<double, double> &position);
};

}