#include <string>

#include "models/GeoPoint2D.h"

namespace controllers {

class Aircraft {
 public:
  static std::string LoadAircraftInCircle(models::GeoPoint2D center, int radius);
};

}