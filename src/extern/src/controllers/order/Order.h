#include <string>

namespace controllers {

class Order {
 public:
  static std::string GetOrderInfo(std::string order_id);
};

}