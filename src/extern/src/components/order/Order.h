#pragma once

#include <string>

#include "core/context_keeper.h"
#include "models/PreOrder.h"
#include "models/Order.h"
#include "models/Pad.h"
#include "models/AircraftClass.h"
#include "price/Price.h"
#include "route/Route.h"
#include "CancelOrderResult.h"

namespace components {

class Order : public ContextKeeper {
 public:
  static models::PreOrder PreOrder(const models::Pad &from, const models::Pad &to, const std::string &aircraft_class_id);
  static models::Order CreateOrder(const models::Pad &from, const models::Pad &to, const std::string &aircraft_class_id);
  static models::Order GetOrderInfo();
  static models::Order ProcessOrdersFromQueue();
  static CancelOrderResult CancelOrder();
};

}