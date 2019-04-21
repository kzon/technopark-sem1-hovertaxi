#pragma once

#include <string>

#include <core/context_keeper.h>
#include "cancel_order_result.h"
#include "models/order.h"
#include "models/pre_order.h"
#include "models/pad.h"
#include "models/geo_point.h"
#include "models/aircraft_class.h"

namespace hovertaxi {

class OrderComponent : public ContextKeeper {
 public:
  static PreOrder GetPreOrderInfo(const Pad &from, const Pad &to, const std::string &aircraft_class_id);
  static Order CreateOrder(const Pad &from, const Pad &to, const std::string &aircraft_class_id);
  static Order GetOrderInfo(const std::string &order_id);
  static Order ProcessOrdersFromQueue();
  static CancelOrderResult CancelOrder(const std::string &order_id);
};

}