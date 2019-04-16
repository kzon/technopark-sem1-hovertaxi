#pragma once

#include "models/order.h"

namespace hovertaxi {

class PriceService {
 public:
  static int GetPrice(const Order &order);
  static int GetCancelPrice(const Order &order);
};

}