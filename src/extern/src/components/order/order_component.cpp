#include "order_component.h"

namespace hovertaxi {

PreOrder OrderComponent::GetPreOrderInfo(const std::string &from_pad_id,
                                         const std::string &to_pad_id,
                                         const std::string &aircraft_class_id) {
  return {};
}

Optional<Order> OrderComponent::CreateOrder(const std::string &from_pad_id,
                                  const std::string &to_pad_id,
                                  const std::string &aircraft_class_id) {
  if (context.user_id.empty())
    return {};
  Order order;
  order.id = "1";
  order.user_id = context.user_id;
  order.from_pad_id = from_pad_id;
  order.to_pad_id = to_pad_id;
  order.aircraft_class_id = aircraft_class_id;
  if (data_manager_.StoreOrder(order))
    return {order};
  return {};
}

Optional<Order> OrderComponent::LoadCurrentOrder() {
  return data_manager_.LoadOrderByUser(context.user_id);
}

Order OrderComponent::ProcessOrdersFromQueue() {
  return {};
}

CancelOrderResult OrderComponent::CancelOrder(const std::string &order_id) {
  return {};
}

}