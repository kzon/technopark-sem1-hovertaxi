#include "Order.h"
#include "components/order/Order.h"

namespace controllers {

std::string Order::GetOrderInfo(std::string order_id) {
  return "testik order id = " + order_id;
}

}