#pragma once

#include <string>
#include "controllers/base/BaseController.h"
#include "models/DataMapper.h"

namespace controllers {

class Order : public BaseController {
 public:
  explicit Order(const models::Context &context) : BaseController(context) {}

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