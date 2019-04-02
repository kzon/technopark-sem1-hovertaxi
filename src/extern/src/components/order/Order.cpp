#include "Order.h"

namespace components {

std::string Order::GetOrderInfo(models::GeoPoint from, models::GeoPoint to, models::AircraftClass aircraft_class) {
  return "order info";
}

models::Order Order::CreateOrder(std::string user_id, models::GeoPoint &from, models::GeoPoint &to) {
  models::Order order{};
  return order;
}

models::Order Order::ProcessOrder(std::string order_id) {
  models::Order order{};
  return order;
}

}