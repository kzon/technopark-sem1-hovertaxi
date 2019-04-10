#pragma once
#include "models/Context.h"

class ContextKeeper {
 public:
  explicit ContextKeeper(const models::Context &context): context(context) {}
 protected:
  models::Context context;
};