#include "order_controller.h"

namespace hovertaxi {

std::string OrderController::GetPreOrderInfo(const std::string &from_pad_id,
                                             const std::string &to_pad_id,
                                             const std::string &aircraft_class_id) {
  PreOrder pre_order{};
  pre_order.price = 78;
  return JSONConverter::ToJSON(pre_order);
}

std::string OrderController::CreateOrder(const std::string &from_pad_id,
                                         const std::string &to_pad_id,
                                         const std::string &aircraft_class_id) {
  return std::string();
}

std::string OrderController::LoadCurrentOrder() {
  Optional<Order> order = order_component_.LoadCurrentOrder();
  return order ? JSONConverter::ToJSON(order.value()) : JSONConverter::Empty();
}

std::string OrderController::CancelOrder() {
  return std::string();
}

}