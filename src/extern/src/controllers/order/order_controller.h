#pragma once

#include <string>

#include "core/context_keeper.h"
#include "models/mongo_data_mapper.h"
#include "models/pre_order.h"
#include "services/json_converter/json_converter.h"

namespace hovertaxi {

class OrderController : public ContextKeeper {
 public:
  explicit OrderController(const Context &context) : ContextKeeper(context) {}

  std::string GetPreOrderInfo(const std::string &from_pad_id,
                              const std::string &to_pad_id,
                              const std::string &aircraft_class_id);
  std::string CreateOrder(const std::string &from_pad_id,
                          const std::string &to_pad_id,
                          const std::string &aircraft_class_id);
  std::string GetOrderInfo();
  std::string CancelOrder();
};

}