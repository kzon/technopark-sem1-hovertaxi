#include "order_component.h"

namespace hovertaxi {

std::string OrderComponent::PreOrder(GeoPoint from, GeoPoint to, AircraftClass aircraft_class) {
  return "order info";
}

Order OrderComponent::CreateOrder(std::string user_id, GeoPoint &from, GeoPoint &to) {
  Order order{};
  return order;
}

Order OrderComponent::ProcessOrder(std::string order_id) {
  Order order{};
  return order;
}

}