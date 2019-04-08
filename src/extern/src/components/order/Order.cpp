#include "Order.h"

namespace components {

models::PreOrder Order::PreOrder(const models::Pad &from, const models::Pad &to, const std::string &aircraft_class_id) {
  return {};
}

models::Order Order::CreateOrder(const models::Pad &from, const models::Pad &to, const std::string &aircraft_class_id) {
  return {};
}

models::Order Order::GetOrderInfo() {
  return {};
}

models::Order Order::ProcessOrdersFromQueue() {
  return {};
}

CancelOrderResult Order::CancelOrder() {
  return {};
}

}