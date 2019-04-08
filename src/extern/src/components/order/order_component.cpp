#include "order_component.h"

namespace hovertaxi {

PreOrder OrderComponent::MakePreOrder(const Pad &from, const Pad &to, const std::string &aircraft_class_id) {
  return {};
}

Order OrderComponent::CreateOrder(const Pad &from, const Pad &to, const std::string &aircraft_class_id) {
  return {};
}

Order OrderComponent::GetOrderInfo(const std::string &order_id) {
  return {};
}

Order OrderComponent::ProcessOrdersFromQueue() {
  return {};
}

CancelOrderResult OrderComponent::CancelOrder(const std::string &order_id) {
  return {};
}

}