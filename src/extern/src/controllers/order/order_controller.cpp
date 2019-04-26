#include "order_controller.h"

namespace hovertaxi {

std::string OrderController::GetPreOrderInfo(const std::string &from_pad_id,
                                             const std::string &to_pad_id,
                                             const std::string &aircraft_class_id) {
  PreOrder pre_order{};
  pre_order.price = 78;
  return JsonConverter::ToJSON(pre_order);
}

std::string OrderController::CreateOrder(const std::string &from_pad_id,
                                         const std::string &to_pad_id,
                                         const std::string &aircraft_class_id) {
  return std::string();
}

std::string OrderController::GetOrderInfo() {
  return "Searching for order for user id = " + context.user_id;
}

std::string OrderController::CancelOrder() {
  return std::string();
}

}