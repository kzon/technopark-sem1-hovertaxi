#pragma once

#include <gtest/gtest.h>
#include <bsoncxx/json.hpp>

#include "services/data_manager/data_manager.h"
#include "services/json/json.h"
#include "models/aircraft.h"

using namespace hovertaxi;

class DataManagerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(DataManagerTest, LoadAircraftById) {
  auto aircraft_classes = DataManager::GetInstance().LoadAircraftClasses();
  auto aircraft_classes_json = JSON::ToJSON(aircraft_classes);
  ASSERT_TRUE(aircraft_classes_json == "[]");
}