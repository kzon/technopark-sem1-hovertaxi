#pragma once

#include "models/order.h"

namespace hovertaxi {

class PriceService {
 public:
  int GetPrice(const Order &order);
  int GetCancelPrice(const Order &order);
};

}