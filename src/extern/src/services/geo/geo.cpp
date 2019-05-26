#include "geo.h"

namespace hovertaxi {

double Geo::DistanceEarth(const GeoPoint &p1, const GeoPoint &p2) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = degreesToRadians(p1.latitude);
  lon1r = degreesToRadians(p1.longitude);
  lat2r = degreesToRadians(p2.latitude);
  lon2r = degreesToRadians(p2.longitude);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * EARTH_RADIUS_KM * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

double Geo::degreesToRadians(double degrees) {
  return (degrees * M_PI) / 180;
}

double Geo::radiansToDegrees(double radians) {
  return (radians * 180) / M_PI;
}
}