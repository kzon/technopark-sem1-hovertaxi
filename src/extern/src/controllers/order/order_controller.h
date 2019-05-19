#pragma once

#include <string>

#include "core/context_keeper.h"
#include "models/mongo_data_mapper.h"
#include "models/pre_order.h"
#include "components/order/order_component.h"
#include "services/data_manager/data_manager.h"
#include "services/json/json.h"
#include "./models/api_order.h"

namespace hovertaxi {

class OrderController : public ContextKeeper {
 public:
  explicit OrderController(const Context &context)
      : ContextKeeper(context), order_component_(context), data_manager_(DataManager::GetInstance()) {}

  std::string GetPreOrderInfo(const std::string &from_pad_id,
                              const std::string &to_pad_id,
                              const std::string &aircraft_class_id);
  std::string CreateOrder(const std::string &from_pad_id,
                          const std::string &to_pad_id,
                          const std::string &aircraft_class_id);
  std::string ProcessOrders();
  std::string LoadCurrentOrder();
  std::string CancelOrder();
 private:
  OrderComponent order_component_;
  const DataManager &data_manager_;

  std::unique_ptr<ApiOrder> ConvertOrderToApi(const Order & order) const;
};

}