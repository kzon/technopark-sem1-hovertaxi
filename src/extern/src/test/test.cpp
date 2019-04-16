#include "gtest/gtest.h"

#include "test/unit/services/data_manager.h"
#include "test/unit/services/event_manager.h"

#include "test/unit/component/order_component.h"
#include "test/unit/component/demo_component.h"
#include "test/unit/component/aircraft_component.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}