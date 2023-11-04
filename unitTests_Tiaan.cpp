#include <iostream>

//include the google test dependencies
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// #include class to best tested
#include "RestaurantTable.h"
#include "StateEmpty.h"

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
    MockRestaurantTable* rt = new MockRestaurantTable(1);
    State* returned;
    returned = rt->getState();
    EXPECT_FALSE(returned->isOccupied()); 

    // // RestaurantTable* rts = new RestaurantTable(1);
    // // EXPECT_EQ(rt->getState()->isOccupied(), false) << "RestaurantTable state not set correctly";
    // EXPECT_CALL(*rt, getState()).Times(1).WillOnce(testing::Return(new StateEmpty(rt)));
    // rt->getState();
}



// test setState
// TEST(RestaurantTableTest, getStateTest) {
//     MockRestaurantTable* rt;
//     State* returned;
//     RestaurantTable* rts = new RestaurantTable(1);
//     returned = rts->getState();
//     EXPECT_EQ(returned->isOccupied(), true) << "RestaurantTable state not set correctly";
// }


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}