
#ifndef HOVERTAXI_TEST_DEMO_COMPONENT_H
#define HOVERTAXI_TEST_DEMO_COMPONENT_H

#include <gtest/gtest.h>
#include "../../../services/data_manager/data_manager.h"
#include "../../../components/demo/demo_component.h"
#include "../../../models/route.h"

using namespace hovertaxi;

class DemoComponentTest: public ::testing::Test {
protected:
    virtual void SetUp(){}
    virtual void TearDown(){}
};

TEST_F(DemoComponentTest, CreateAircraftsRoutes){
    DemoComponent::CreateAircraftsRoutes();
    //check if routes haven't join points
}

TEST_F(DemoComponentTest, UpdateAircraftsPositions){
    int countOfCalls = 5;
    for(int i = 0; i < countOfCalls; i++){
        DemoComponent::UpdateAircraftsPositions();
    }
}

#endif //HOVERTAXI_TEST_DEMO_COMPONENT_H
