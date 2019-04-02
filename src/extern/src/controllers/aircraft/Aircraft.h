#include <string>

#include "models/GeoPoint.h"

namespace controllers {

class Aircraft {
 public:
  static std::string LoadAircraftInCircle();
  static std::string LoadAircraftClasses();
};

}