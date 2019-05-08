#include "order_component.h"

namespace hovertaxi {

PreOrder OrderComponent::GetPreOrderInfo(const Pad &from, const Pad &to, const std::string &aircraft_class_id) {
  return {};
}

Order OrderComponent::CreateOrder(const Pad &from, const Pad &to, const std::string &aircraft_class_id) {
  return {};
}

Optional<Order> OrderComponent::LoadCurrentOrder() {
  return ServiceLocator::GetDataManager().LoadOrderByUser(context.user_id);
}

Order OrderComponent::ProcessOrdersFromQueue() {
  return {};
}

CancelOrderResult OrderComponent::CancelOrder(const std::string &order_id) {
  return {};
}

}