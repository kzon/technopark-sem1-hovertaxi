#ifndef HOVERTAXI_TEST_ORDER_COMPONENT_H
#define HOVERTAXI_TEST_ORDER_COMPONENT_H

#include <gtest/gtest.h>
#include "../../../services/data_manager/data_manager.h"
#include "../../../components/order/order_component.h"
#include "../../../models/aircraft.h"
#include "../../../models/geo_point.h"

using namespace hovertaxi;

class OrderComponentTest: public ::testing::Test {
protected:
    virtual void SetUp(){}
    virtual void TearDown(){}
};


TEST_F(OrderComponentTest, CreateOrder){

}

TEST_F(OrderComponentTest, GetOrderInfo){

}

TEST_F(OrderComponentTest, ProcessOrdersFromQueue){

}

TEST_F(OrderComponentTest, CancelOrder){

}


#endif //HOVERTAXI_TEST_AIRCRAFT_COMPONENT_H
