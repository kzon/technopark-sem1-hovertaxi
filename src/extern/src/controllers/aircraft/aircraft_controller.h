#include <string>

#include "models/geo_point.h"

namespace hovertaxi {

class AircraftController {
 public:
  static std::string LoadAircraftInCircle();
  static std::string LoadAircraftClasses();
};

}