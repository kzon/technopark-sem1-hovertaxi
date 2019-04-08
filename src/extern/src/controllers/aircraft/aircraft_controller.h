#include <string>

#include "controllers/base/base_controller.h"
#include "models/geo_point.h"

namespace hovertaxi {

class AircraftController : public BaseController {
 public:
  explicit AircraftController(const Context &context) : BaseController(context) {}

  std::string LoadAircraftInCircle(const std::pair<double, double> &center, int radius);
  std::string LoadCurrentOrderAircraft();
  std::string LoadAircraftClasses();
  std::string LoadNearestPads(const std::pair<double, double> &position);
};

}