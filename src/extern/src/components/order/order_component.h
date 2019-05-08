#pragma once

#include <string>

#include "core/context_keeper.h"
#include "cancel_order_result.h"
#include "models/order.h"
#include "models/pre_order.h"
#include "models/pad.h"
#include "models/geo_point.h"
#include "models/aircraft_class.h"
#include "services/service_locator/service_locator.h"

namespace hovertaxi {

class OrderComponent : public ContextKeeper {
 public:
  explicit OrderComponent(const Context &context) : ContextKeeper(context) {}

  PreOrder GetPreOrderInfo(const Pad &from, const Pad &to, const std::string &aircraft_class_id);
  Order CreateOrder(const Pad &from, const Pad &to, const std::string &aircraft_class_id);
  Optional<Order> LoadCurrentOrder();
  Order ProcessOrdersFromQueue();
  CancelOrderResult CancelOrder(const std::string &order_id);
};

}