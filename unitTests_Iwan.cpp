#include <iostream>

//include the google test dependencies
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// #include class to best tested
#include "Waiter.h"

// #include all relative classes needed for successful testing

// make a MOCK class to replace the class that is being tested
class MockWaiter : public Waiter {
    public:
        MockWaiter(std::string name, int totalOrders, FloorColleague *fc) : Waiter(name, totalOrders, fc) {}
        MOCK_METHOD(void, setWaiterState, (WaiterState* state));
        MOCK_METHOD(void, addItem, (RestaurantTable* rt, std::string m));
        MOCK_METHOD(void, confirmOrder, (RestaurantTable* rt));
        MOCK_METHOD(void, addOrder, (RestaurantTable* rt));
        MOCK_METHOD(Order*, getOrder, (RestaurantTable* rt));
        MOCK_METHOD(bool, isAvailable, ());
        MOCK_METHOD(std::string, getName, ());
        MOCK_METHOD(MenuItem*, getMenuItem, (std::string name));
        MOCK_METHOD(int, getBusyOrders, ());
};

// test waiter
TEST(WaiterTest, waiterStateSet) {
    Waiter *w = new Waiter("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(w);
    w->setWaiterState(ws);
    EXPECT_EQ(w->isAvailable(), true) << "Waiter state not set correctly";
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}