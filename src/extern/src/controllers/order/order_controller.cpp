#include "order_controller.h"

namespace hovertaxi {

std::string OrderController::PreOrder(const std::string &from_pad_id,
                            const std::string &to_pad_id,
                            const std::string &aircraft_class_id) {
  return "Hello! You passed " + from_pad_id + to_pad_id + aircraft_class_id;
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