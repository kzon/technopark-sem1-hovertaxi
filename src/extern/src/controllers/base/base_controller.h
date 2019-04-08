#pragma once
#include "models/context.h"

namespace hovertaxi {

class BaseController {
 public:
  explicit BaseController(const Context &context): context(context) {}
 protected:
  Context context;
};

}