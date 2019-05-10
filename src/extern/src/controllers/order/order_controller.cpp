#include "order_controller.h"

namespace hovertaxi {

std::string OrderController::GetPreOrderInfo(const std::string &from_pad_id,
                                             const std::string &to_pad_id,
                                             const std::string &aircraft_class_id) {
  PreOrder pre_order{};
  pre_order.price = 78;
  return JSON::ToJSON(pre_order);
}

std::string OrderController::CreateOrder(const std::string &from_pad_id,
                                         const std::string &to_pad_id,
                                         const std::string &aircraft_class_id) {
  auto order = order_component_.CreateOrder(from_pad_id, to_pad_id, aircraft_class_id);
  return order ? JSON::ToJSON(order.value()) : JSON::Empty();
}

std::string OrderController::LoadCurrentOrder() {
  Optional<Order> order = order_component_.LoadCurrentOrder();
  return order ? JSON::ToJSON(order.value()) : JSON::Empty();
}

std::string OrderController::CancelOrder() {
  return std::string();
}

}