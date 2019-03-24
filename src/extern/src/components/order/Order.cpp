#include "Order.h"

#include <thread>
#include <chrono>

namespace components {

bool Order::LoadOrderById(unsigned order_id, models::Order &order) {
  return false;
}

models::Order Order::CreateOrder(unsigned user_id, models::GeoPoint &from, models::GeoPoint &to) {
  models::Order order;
  return order;
}

models::Order Order::ProcessOrder(unsigned order_id) {
  std::this_thread::sleep_for(std::chrono::seconds(3));
  models::Order order;
  order.id = order_id;
  return order;
}

}

