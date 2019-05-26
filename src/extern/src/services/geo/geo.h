#pragma once

#include <math.h>
#include <cmath>

#include "models/geo_point.h"

#define EARTH_RADIUS_KM 6371.0

namespace hovertaxi {

class Geo {
 public:
  static double DistanceEarth(const GeoPoint &p1, const GeoPoint &p2);
 private:
  static double degreesToRadians(double degrees);
  static double radiansToDegrees(double radians);
};

}