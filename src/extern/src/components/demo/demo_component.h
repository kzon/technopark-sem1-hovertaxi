#pragma once

#include <string>

namespace hovertaxi {

class DemoComponent {
 public:
  static void CreateAircraftsRoutes();
  static void UpdateAircraftsPositions();
  static void AssignMoveToNearestPadRoute(const std::string &aircraft_id);
};

}