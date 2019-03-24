<<<<<<< HEAD
#include "components/order/Order.h"

unsigned user_id = 2;
unsigned created_order_id;

TEST(CreateOrderTest, NewOrderCreated) {
  models::GeoPoint from{58.234234, 32.3241342}, to{58.234144, 32.3241500};
  auto created_order = components::Order::CreateOrder(user_id, from, to);
  created_order_id = created_order.id;
  ASSERT_EQ(created_order.user_id, user_id);
  ASSERT_EQ(created_order.status, models::OrderStatus::NEW);
  ASSERT_TRUE(created_order.from == from);
  ASSERT_TRUE(created_order.to == to);
}

TEST(CreateOrderTest, CreatedOrderSaved) {
  models::Order order;
  bool is_success = components::Order::LoadOrderById(created_order_id, order);
  ASSERT_TRUE(is_success);
  ASSERT_EQ(order.id, created_order_id);
  ASSERT_EQ(order.user_id, user_id);
}
=======
>>>>>>> b71a227436914cf049dbd2ab210f3e8c01989e87
