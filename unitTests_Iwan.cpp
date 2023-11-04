#include <iostream>

//include the google test dependencies
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// #include class to best tested
#include "Waiter.h"

// // make a MOCK class to replace the class that is being tested
// class MockWaiter : public Waiter {
//     public:
//         MockWaiter(std::string name, int totalOrders, FloorColleague *fc) : Waiter(name, totalOrders, fc) {}
//         MOCK_METHOD(void, setWaiterState, (WaiterState* state), (override));
//         MOCK_METHOD(void, addItem, (RestaurantTable* rt, std::string m), (override));
//         MOCK_METHOD(void, confirmOrder, (RestaurantTable* rt), (override));
//         MOCK_METHOD(void, addOrder, (RestaurantTable* rt), (override));
//         MOCK_METHOD(Order*, getOrder, (RestaurantTable* rt), (override));
//         MOCK_METHOD(bool, isAvailable, (), (override));
//         MOCK_METHOD(std::string, getName, (), (override));
//         MOCK_METHOD(MenuItem*, getMenuItem, (std::string name), (override));
//         MOCK_METHOD(int, getBusyOrders, (), (override));
// };

// #include all relative classes needed for successful testing

//our first unit test



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}