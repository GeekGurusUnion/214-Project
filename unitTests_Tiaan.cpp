#include <iostream>

//include the google test dependencies
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// #include class to best tested
#include "RestaurantTable.h"
#include "StateEmpty.h"
#include "Waiter.h"

// #include all relative classes needed for successful testing

// make a MOCK class to replace the class that is being tested
class MockRestaurantTable : public RestaurantTable {
    public:
        MockRestaurantTable(int i, int t) : RestaurantTable(i, t) {}
        MOCK_METHOD1(setState, void (State* state));
        MOCK_METHOD0(getState, State*());
        MOCK_METHOD0(occupy, void ());
        MOCK_METHOD0(getWaiter, Waiter* ());
        MOCK_METHOD1(setWaiter, void (Waiter* waiter));
        MOCK_METHOD0(getOrder, Order* ());
        MOCK_METHOD0(isAvailable, bool ());
        MOCK_METHOD0(getTableNumber, int ());
        MOCK_METHOD0(printBill, void ());
        MOCK_METHOD0(getTableSize, int ());
        MOCK_METHOD0(serve, void ());
        MOCK_METHOD0(getCostPerPerson, float ());
        MOCK_METHOD1(setCostPerPerson, void (int cost));
        MOCK_METHOD0(getTableCost, float ());
        MOCK_METHOD1(setTableSize, void (int size));
        MOCK_METHOD0(unsetWaiter, void ());
};

// test getState
TEST(RestaurantTableTest, getStateTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, getState()).Times(1).WillOnce(testing::Return(new StateEmpty(&rt)));
    EXPECT_FALSE(rt.getState()->isOccupied()) << "RestaurantTable state not set correctly";
}

// test setState
TEST(RestaurantTableTest, setStateTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, setState(testing::_)).Times(1);
    rt.setState(new StateEmpty(&rt));
}

// test occupy
TEST(RestaurantTableTest, occupyTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, occupy()).Times(1);
    rt.occupy();
}

// test getWaiter
TEST(RestaurantTableTest, getWaiterTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, getWaiter()).Times(1);
    rt.getWaiter();
}

// test setWaiter
TEST(RestaurantTableTest, setWaiterTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, setWaiter(testing::_)).Times(1);
    rt.setWaiter(new Waiter("Bob", 5, nullptr));
}

// test getOrder
TEST(RestaurantTableTest, getOrderTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, getOrder()).Times(1);
    rt.getOrder();
}

// test isAvailable
TEST(RestaurantTableTest, isAvailableTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, isAvailable()).Times(1);
    rt.isAvailable();
}

// test getTableNumber
TEST(RestaurantTableTest, getTableNumberTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, getTableNumber()).Times(1);
    rt.getTableNumber();
}

// test printBill
TEST(RestaurantTableTest, printBillTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, printBill()).Times(1);
    rt.printBill();
}

// test getTableSize
TEST(RestaurantTableTest, getTableSizeTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, getTableSize()).Times(1);
    rt.getTableSize();
}

// test serve
TEST(RestaurantTableTest, serveTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, serve()).Times(1);
    rt.serve();
}

// test getCostPerPerson
TEST(RestaurantTableTest, getCostPerPersonTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, getCostPerPerson()).Times(1);
    rt.getCostPerPerson();
}

// test setCostPerPerson
TEST(RestaurantTableTest, setCostPerPersonTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, setCostPerPerson(testing::_)).Times(1);
    rt.setCostPerPerson(5);
}

// test getTableCost
TEST(RestaurantTableTest, getTableCostTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, getTableCost()).Times(1);
    rt.getTableCost();
}

// test setTableSize
TEST(RestaurantTableTest, setTableSizeTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, setTableSize(testing::_)).Times(1);
    rt.setTableSize(5);
}

// test unsetWaiter
TEST(RestaurantTableTest, unsetWaiterTest) {
    MockRestaurantTable rt(1, 1);
    EXPECT_CALL(rt, unsetWaiter()).Times(1);
    rt.unsetWaiter();
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}