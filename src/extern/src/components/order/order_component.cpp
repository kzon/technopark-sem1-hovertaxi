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
  order.status = Order::STATUS_NEW;
  order.from_pad_id = from_pad_id;
  order.to_pad_id = to_pad_id;
  order.aircraft_class_id = aircraft_class_id;
  if (data_manager_.StoreOrder(order))
    return {order};
  return {};
}

Optional<Order> OrderComponent::LoadCurrentOrder() {
  DataFilter filter;
  DataFilterBuilder::StringNotEquals(filter, "status", Order::STATUS_FINISHED);
  DataFilterBuilder::StringNotEquals(filter, "status", Order::STATUS_CANCELED);
  return data_manager_.LoadOrderByUserAndFilter(context.user_id, filter);
}

ProcessOrdersResult OrderComponent::ProcessOrders() {
  ProcessOrdersResult result{};
  auto orders = data_manager_.LoadUnprocessedOrders();
  for (const auto &order_pointer : orders) {
    Order order = *order_pointer;
    auto from_pad_result = data_manager_.LoadPadById(order.from_pad_id);
    if (!from_pad_result)
      throw std::bad_exception();
    Pad from_pad = from_pad_result.value();

    result.orders_processed++;

    auto aircraft_result = data_manager_.LoadNearestFreeAircraft(from_pad.position, order.aircraft_class_id);
    if (!aircraft_result) {
      result.no_suitable_aircraft++;
      continue;
    }
    Aircraft aircraft = aircraft_result.value();

    order.assigned_aircraft_id = aircraft.id;
    order.status = Order::STATUS_AIRCRAFT_ASSIGNED;
    data_manager_.StoreOrder(order);

    aircraft.is_assigned = true;
    data_manager_.StoreAircraft(aircraft);

    result.aircrafts_assigned++;
  }
  return result;
}

CancelOrderResult OrderComponent::CancelOrder(const std::string &order_id) {
  return {};
}

}