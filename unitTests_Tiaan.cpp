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
        MockRestaurantTable(int i) : RestaurantTable(i) {}
        MOCK_METHOD0(getState, State*());
        MOCK_METHOD1(setState, void (State* state));
        MOCK_METHOD0(occupy, void ());
        MOCK_METHOD0(empty, void ());
        MOCK_METHOD2(notifyWaiter, void (std::string action, bool isItem));
        MOCK_METHOD0(getWaiter, Waiter* ());
        MOCK_METHOD1(setWaiter, void (Waiter* waiter));
        MOCK_METHOD0(confirmOrder, void ());
        MOCK_METHOD0(welcomeWaiter, void ());
        MOCK_METHOD1(addToOrder, void (std::string item));
        MOCK_METHOD0(getOrder, Order* ());
        MOCK_METHOD0(isAvailable, bool ());
        MOCK_METHOD0(getTableNumber, int ());
};

// test getState
TEST(RestaurantTableTest, getStateTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, getState()).Times(1).WillOnce(testing::Return(new StateEmpty(&rt)));
    EXPECT_FALSE(rt.getState()->isOccupied()) << "RestaurantTable state not set correctly"; 

    // State* returned;
    // returned = rt->getState();
    // // RestaurantTable* rts = new RestaurantTable(1);
    // // EXPECT_EQ(rt->getState()->isOccupied(), false) << "RestaurantTable state not set correctly";
    // EXPECT_CALL(*rt, getState()).Times(1).WillOnce(testing::Return(new StateEmpty(rt)));
    // rt->getState();
}



// test setState
TEST(RestaurantTableTest, setStateTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, setState(testing::_)).Times(1);
    rt.setState(new StateEmpty(&rt));

//     State* returned;
//     RestaurantTable* rts = new RestaurantTable(1);
//     returned = rts->getState();
//     EXPECT_EQ(returned->isOccupied(), true) << "RestaurantTable state not set correctly";
}

// test occupy
TEST(RestaurantTableTest, occupyTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, occupy()).Times(1);
    rt.occupy();
}

// test empty
TEST(RestaurantTableTest, emptyTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, empty()).Times(1);
    rt.empty();
}

// test notifyWaiter
TEST(RestaurantTableTest, notifyWaiterTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, notifyWaiter(testing::_, testing::_)).Times(1);
    rt.notifyWaiter("test", true);
}

// test getWaiter
TEST(RestaurantTableTest, getWaiterTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, getWaiter()).Times(1);
    rt.getWaiter();
}

// test setWaiter
TEST(RestaurantTableTest, setWaiterTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, setWaiter(testing::_)).Times(1);
    rt.setWaiter(new Waiter("Bob", 5, nullptr));
}

// test confirmOrder
TEST(RestaurantTableTest, confirmOrderTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, confirmOrder()).Times(1);
    rt.confirmOrder();
}

// test welcomeWaiter
TEST(RestaurantTableTest, welcomeWaiterTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, welcomeWaiter()).Times(1);
    rt.welcomeWaiter();
}

// test addToOrder
TEST(RestaurantTableTest, addToOrderTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, addToOrder(testing::_)).Times(1);
    rt.addToOrder("test");
}

// test getOrder
TEST(RestaurantTableTest, getOrderTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, getOrder()).Times(1);
    rt.getOrder();
}

// test isAvailable
TEST(RestaurantTableTest, isAvailableTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, isAvailable()).Times(1);
    rt.isAvailable();
}

// test getTableNumber
TEST(RestaurantTableTest, getTableNumberTest) {
    MockRestaurantTable rt(1);
    EXPECT_CALL(rt, getTableNumber()).Times(1);
    rt.getTableNumber();
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}