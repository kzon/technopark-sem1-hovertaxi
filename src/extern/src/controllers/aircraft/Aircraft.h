#include <string>

#include "controllers/base/BaseController.h"
#include "models/GeoPoint.h"

namespace controllers {

class Aircraft : public BaseController {
 public:
  explicit Aircraft(const models::Context &context) : BaseController(context) {}

  std::string LoadAircraftInCircle(const std::pair<double, double> &center, int radius);
  std::string LoadCurrentOrderAircraft();
  std::string LoadAircraftClasses();
  std::string LoadNearestPads(const std::pair<double, double> &position);
};

}