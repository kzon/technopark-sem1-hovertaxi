#pragma once

#include <string>

#include "models/PreOrder.h"
#include "models/Order.h"
#include "models/Pad.h"
#include "models/AircraftClass.h"
#include "price/Price.h"
#include "route/Route.h"
#include "CancelOrderResult.h"

namespace components {

class Order {
 public:
  static models::PreOrder PreOrder(const models::Pad &from, const models::Pad &to, const std::string &aircraft_class_id);
  static models::Order CreateOrder(const models::Pad &from, const models::Pad &to, const std::string &aircraft_class_id);
  static models::Order GetOrderInfo(const std::string &order_id);
  static models::Order ProcessOrdersFromQueue();
  static CancelOrderResult CancelOrder(const std::string &order_id);
};

}