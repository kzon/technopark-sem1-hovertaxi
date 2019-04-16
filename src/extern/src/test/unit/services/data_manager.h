#pragma once

#include <gtest/gtest.h>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include "services/data_manager/data_manager.h"
#include "services/service_locator/service_locator.h"
#include "models/aircraft.h"

using namespace hovertaxi;

class DataManagerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(DataManagerTest, LoadAircraftClasses) {
  auto vec = ServiceLocator::GetDataManager().LoadAircraftClasses();

  ASSERT_EQ(0, vec.size());
}

TEST_F(DataManagerTest, LoadAircraftById) {

  auto aircraft1 = ServiceLocator::GetDataManager().LoadAircraftById("1");
  ASSERT_TRUE(aircraft1);

  auto aircraft2 = ServiceLocator::GetDataManager().LoadAircraftById("-1");
  ASSERT_TRUE(aircraft2);
}