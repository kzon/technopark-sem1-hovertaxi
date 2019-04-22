#pragma once

#include <gtest/gtest.h>
#include <bsoncxx/json.hpp>

#include "services/data_manager/data_manager.h"
#include "services/service_locator/service_locator.h"
#include "models/aircraft.h"

using namespace hovertaxi;

class DataManagerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(DataManagerTest, LoadAircraftById) {

  auto aircrafts = ServiceLocator::GetDataManager().LoadAircraftClassesAsJSON();
  ASSERT_TRUE(aircrafts == "[]");
}