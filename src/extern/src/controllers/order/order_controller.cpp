#include "order_controller.h"

namespace hovertaxi {

std::string OrderController::GetPreOrderInfo(const std::string &from_pad_id,
                                             const std::string &to_pad_id,
                                             const std::string &aircraft_class_id) {
  auto pre_order = order_component_.GetPreOrderInfo(from_pad_id, to_pad_id, aircraft_class_id);
  return JSON::ToJSON(pre_order);
}

std::string OrderController::CreateOrder(const std::string &from_pad_id,
                                         const std::string &to_pad_id,
                                         const std::string &aircraft_class_id) {
  auto order = order_component_.CreateOrder(from_pad_id, to_pad_id, aircraft_class_id);
  return order ? JSON::ToJSON(order.value()) : JSON::Empty();
}

std::string OrderController::ProcessOrders() {
  size_t orders_processed = order_component_.ProcessOrders();
  return std::to_string(orders_processed);
}

std::string OrderController::LoadCurrentOrder() {
  Optional<Order> order = order_component_.LoadCurrentOrder();
  return order ? JSON::ToJSON(order.value()) : JSON::Empty();
}

std::string OrderController::CancelOrder() {
  return std::string();
}

}