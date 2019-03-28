#pragma once

namespace models {

struct GeoPoint2D {
  double latitude;
  double longitude;

  bool operator==(const GeoPoint2D other) {
    return latitude == other.latitude && longitude == other.longitude;
  }
};

}