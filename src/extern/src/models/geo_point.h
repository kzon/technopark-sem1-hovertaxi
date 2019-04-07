#pragma once

namespace hovertaxi {

struct GeoPoint {
  double latitude;
  double longitude;

  bool operator==(const GeoPoint other) {
    return latitude == other.latitude && longitude == other.longitude;
  }
};

}