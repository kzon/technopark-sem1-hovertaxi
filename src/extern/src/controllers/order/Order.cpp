#include "Order.h"
#include "components/order/Order.h"

namespace controllers {

std::string Order::PreOrder(const std::string &from_pad_id,
                            const std::string &to_pad_id,
                            const std::string &aircraft_class_id) {
  return "Hello! You passed " + from_pad_id + to_pad_id + aircraft_class_id;
}

std::string Order::CreateOrder(const std::string &from_pad_id,
                               const std::string &to_pad_id,
                               const std::string &aircraft_class_id) {
  return std::string();
}

std::string Order::GetOrderInfo() {
  return "Searching for order for user id = " + context.user_id;
}

std::string Order::CancelOrder() {
  return std::string();
}

}