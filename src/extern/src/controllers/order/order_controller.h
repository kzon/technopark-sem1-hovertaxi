#pragma once

#include <string>
#include "controllers/base/base_controller.h"
#include "models/data_mapper.h"

namespace hovertaxi {

class OrderController : public BaseController {
 public:
  explicit OrderController(const Context &context) : BaseController(context) {}

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