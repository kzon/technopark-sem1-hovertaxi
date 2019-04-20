#pragma once

#include "models/context.h"

namespace hovertaxi {

class ContextKeeper {
 public:
  explicit ContextKeeper(const Context &context) : context(context) {}

 protected:
  Context context;
};

}