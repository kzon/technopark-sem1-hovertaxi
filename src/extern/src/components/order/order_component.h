#pragma once

#include <string>
#include <exception>

#include "core/context_keeper.h"
#include "process_orders_result.h"
#include "cancel_order_result.h"
#include "models/order.h"
#include "models/pre_order.h"
#include "models/pad.h"
#include "models/geo_point.h"
#include "models/aircraft_class.h"
#include "services/data_manager/data_manager.h"
#include "price_service/price_service.h"
#include "./route_service/route_service.h"

namespace hovertaxi {

class OrderComponent : public ContextKeeper {
 public:
  explicit OrderComponent(const Context &context)
      : ContextKeeper(context), data_manager_(DataManager::GetInstance()) {}

  PreOrder GetPreOrderInfo(const std::string &from_pad_id,
                           const std::string &to_pad_id,
                           const std::string &aircraft_class_id) const;
  Optional<Order> CreateOrder(const std::string &from_pad_id,
                              const std::string &to_pad_id,
                              const std::string &aircraft_class_id) const;
  Optional<Order> LoadCurrentOrder() const;

  int GetTimeToArrival(const Order &order) const;

  /* Returns number of processed orders */
  ProcessOrdersResult ProcessOrders() const;

  CancelOrderResult CancelOrder(const std::string &order_id) const;

 private:
  const DataManager &data_manager_;
  RouteService route_service_;
};

}