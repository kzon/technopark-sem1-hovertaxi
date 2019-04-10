#pragma once

#include <string>
#include "core/context_keeper.h"
#include "models/DataMapper.h"

namespace controllers {

class Order : public ContextKeeper {
 public:
  explicit Order(const models::Context &context) : ContextKeeper(context) {}

  std::string PreOrder(const std::string &from_pad_id,
                       const std::string &to_pad_id,
                       const std::string &aircraft_class_id);
  std::string CreateOrder(const std::string &from_pad_id,
                          const std::string &to_pad_id,
                          const std::string &aircraft_class_id);
  std::string GetOrderInfo();
  std::string CancelOrder();
};

}