#include "components/order/Order.h"
#include "models/Order.cpp"
#include "models/GeoPoint.cpp"

TEST(CreateOrderTest, OrderCreated) {
  models::GeoPoint from{58.234234, 32.3241342}, to{58.234144, 32.3241500};
  auto created_order = components::Order::CreateOrder(from, to);
  ASSERT_TRUE(created_order.from == from);
  ASSERT_TRUE(created_order.to == to);
}