#include "order_controller.h"

namespace hovertaxi {

std::string OrderController::GetPreOrderInfo(const std::string &from_pad_id,
                                             const std::string &to_pad_id,
                                             const std::string &aircraft_class_id) {
  return "{\n"
         "        \"route\": {\n"
         "          \"points\": [\n"
         "            [55.750512, 37.539209],\n"
         "            [55.788572, 37.677854]\n"
         "          ],\n"
         "          \"time\": 8\n"
         "        },\n"
         "        \"price\": 755\n"
         "      }";
}

std::string OrderController::CreateOrder(const std::string &from_pad_id,
                                         const std::string &to_pad_id,
                                         const std::string &aircraft_class_id) {
  auto order = order_component_.CreateOrder(from_pad_id, to_pad_id, aircraft_class_id);
  return order ? JSON::ToJSON(order.value()) : JSON::Empty();
}

std::string OrderController::LoadCurrentOrder() {
  Optional<Order> order = order_component_.LoadCurrentOrder();
  return order ? JSON::ToJSON(order.value()) : JSON::Empty();
}

std::string OrderController::CancelOrder() {
  return std::string();
}

}