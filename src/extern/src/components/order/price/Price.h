#include "models/Order.h"

namespace components {

class Price {
 public:
  static int GetPrice(const models::Order &order);
  static int GetCancelPrice(const models::Order &order);
};

}