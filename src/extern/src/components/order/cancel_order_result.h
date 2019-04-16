#pragma once

#include <string>

namespace hovertaxi {

struct CancelOrderResult {
  std::string result;
  int cancel_price;
};

}