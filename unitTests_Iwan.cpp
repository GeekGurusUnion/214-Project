#include <iostream>
#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Waiter.h"

class MockWaiter : public Waiter {
public:
    MockWaiter(std::string name, int totalOrders, FloorColleague* fc) : Waiter(name, totalOrders, fc) {}
    MOCK_METHOD1(setWaiterState, void(WaiterState*));
    MOCK_METHOD2(addItem, void(RestaurantTable*, std::string));
    MOCK_METHOD1(confirmOrder, void(RestaurantTable*));
    MOCK_METHOD1(addOrder, void(RestaurantTable*));
    MOCK_METHOD1(getOrder, Order*(RestaurantTable*));
    MOCK_METHOD0(isAvailable, bool());
    MOCK_METHOD0(getName, std::string());
    MOCK_METHOD1(getMenuItem, MenuItem*(std::string));
    MOCK_METHOD0(getBusyOrders, int());
};

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(MockWaiter, waiterName) {
    MockWaiter w("Bob", 5, nullptr);
    EXPECT_CALL(w, getName()).Times(1).WillOnce(testing::Return("Bob"));
    w.getName();
}
TEST(MockWaiter, waiterStateSet) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    EXPECT_CALL(w, setWaiterState(ws)).Times(1);
    w.setWaiterState(ws);
}
TEST(MockWaiter, waiterConfirmOrder) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    RestaurantTable *rt = new RestaurantTable(1);
    rt->setWaiter(&w);
    EXPECT_CALL(w, confirmOrder(rt)).Times(1);
    w.confirmOrder(rt);
}


