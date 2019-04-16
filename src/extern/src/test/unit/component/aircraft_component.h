#pragma once

#include <gtest/gtest.h>
#include <cmath>
#include <vector>

#include "services/data_manager/data_manager.h"
#include "components/aircraft/aircraft_component.h"
#include "models/aircraft.h"
#include "models/geo_point.h"

using namespace hovertaxi;

class AircraftComponentTest: public ::testing::Test {
protected:
    virtual void SetUp(){}
    virtual void TearDown(){}
};

TEST_F(AircraftComponentTest, LoadAircraftInCircle){

    const GeoPoint p1 = {55.751574, 37.573856};
    int radius = 20000;

    auto vec1 = AircraftComponent::LoadAircraftInCircle(p1, radius);
    for(const auto& aircraft : vec1) {
        double lat = aircraft.position.latitude;
        double lon = aircraft.position.longitude;
        EXPECT_EQ(true,  std::abs(lat - p1.latitude) < radius);
        EXPECT_EQ(true,  std::abs(lon - p1.longitude) < radius);
    }

    GeoPoint p2{56.129057, 40.406635};
    auto vec2 = AircraftComponent::LoadAircraftInCircle(p2, radius);
    EXPECT_EQ(0,  vec2.size());
}

