#include "order_component.h"

namespace hovertaxi {

PreOrder OrderComponent::GetPreOrderInfo(const std::string &from_pad_id,
                                         const std::string &to_pad_id,
                                         const std::string &aircraft_class_id) {
  PreOrder pre_order;

  Optional<Pad> from_pad_result = data_manager_.LoadPadById(from_pad_id),
      to_pad_result = data_manager_.LoadPadById(to_pad_id);
  if (!from_pad_result || !to_pad_result)
    throw std::bad_exception();
  Pad from_pad = from_pad_result.value(),
      to_pad = to_pad_result.value();

  Route route;
  route.points.push_back(from_pad.position);
  route.points.push_back(to_pad.position);
  route.time = 8;

  pre_order.route = route;
  pre_order.price = 755;
  return pre_order;
}

Optional<Order> OrderComponent::CreateOrder(const std::string &from_pad_id,
                                            const std::string &to_pad_id,
                                            const std::string &aircraft_class_id) {
  if (context.user_id.empty())
    return {};
  Order order;
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