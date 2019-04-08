#pragma once
#include "models/Context.h"

namespace controllers {

class BaseController {
 public:
  explicit BaseController(const models::Context &context): context(context) {}
 protected:
  models::Context context;
};

}