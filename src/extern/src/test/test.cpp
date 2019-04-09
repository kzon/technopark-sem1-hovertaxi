#include "gtest/gtest.h"

#include "unit/services/test_data_manager.h"
#include "unit/component/test_order_component.h"
#include "unit/component/test_demo_component.h"
#include "unit/component/test_aircraft_component.h"


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}