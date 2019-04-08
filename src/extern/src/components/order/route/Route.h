#include <vector>
#include "models/Route.h"
#include "models/Order.h"

namespace components {

class Route {
 public:
  static models::Route GetRoute(const models::Order &order);
  static std::vector<models::Route> GetCrossingRoutes(const models::Route &route);
};

}