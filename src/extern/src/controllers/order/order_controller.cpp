#include "order_controller.h"

namespace hovertaxi {

std::string OrderController::GetPreOrderInfo(const std::string &from_pad_id,
                                             const std::string &to_pad_id,
                                             const std::string &aircraft_class_id) {
  auto pre_order = order_component_.GetPreOrderInfo(from_pad_id, to_pad_id, aircraft_class_id);
  return JSON::ToJSON(pre_order);
}

std::string OrderController::CreateOrder(const std::string &from_pad_id,
                                         const std::string &to_pad_id,
                                         const std::string &aircraft_class_id) {
  auto order_result = order_component_.CreateOrder(from_pad_id, to_pad_id, aircraft_class_id);
  if (!order_result)
    return JSON::Empty();
  ApiOrder api_order = *ConvertOrderToApi(order_result.value());
  return JSON::ToJSON(api_order);
}

std::string OrderController::ProcessOrders() {
  return JSON::ToJSON(order_component_.ProcessOrders());
}

std::string OrderController::LoadCurrentOrder() {
  Optional<Order> order_result = order_component_.LoadCurrentOrder();
  if (!order_result)
    return JSON::Empty();
  ApiOrder api_order = *ConvertOrderToApi(order_result.value());
  return JSON::ToJSON(api_order);
}

std::string OrderController::CancelOrder() {
  return std::string();
}

std::unique_ptr<ApiOrder> OrderController::ConvertOrderToApi(const Order &order) const {
  std::unique_ptr<ApiOrder> api_order(new ApiOrder);
  api_order->status = order.status;
  api_order->from_pad = data_manager_.LoadPadById(order.from_pad_id).value();
  api_order->to_pad = data_manager_.LoadPadById(order.to_pad_id).value();
  if (!order.aircraft_class_id.empty())
    api_order->aircraft_class = data_manager_.LoadAircraftClassById(order.aircraft_class_id).value();
  if (!order.assigned_aircraft_id.empty()) {
    api_order->assigned_aircraft = data_manager_.LoadAircraftById(order.assigned_aircraft_id).value();
    api_order->assigned_aircraft_model =
        data_manager_.LoadAircraftModelById(api_order->assigned_aircraft.model_id).value();
  }
  api_order->route = order.route;
  api_order->price = order.price;
  return api_order;
}

}