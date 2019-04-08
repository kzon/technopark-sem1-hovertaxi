#pragma once

#include <string>

namespace components {

struct CancelOrderResult {
  std::string result;
  int cancel_price;
};

}