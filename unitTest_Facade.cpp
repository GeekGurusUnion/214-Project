#include <iostream>
#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Facade.h"

class MockFacade : private Facade {
    public:        
        MockFacade() : Facade() {} // Facade();
        MOCK_METHOD0(getSeated, void());  // void getSeated();
        MOCK_CONST_METHOD2(addToOrder, void(int, std::string)); // void addToOrder(int tableNumber, std::string itemName);
        MOCK_CONST_METHOD1(confirmOrder, void(int)); // void confirmOrder(int tableNumber);
        MOCK_CONST_METHOD1(leaveTable, void(int)); // void leaveTable(int tableNumber);
        MOCK_METHOD0(getWaiterIterator, Iterator*());  // WaiterIterator* createWaiterIterator();
        MOCK_METHOD0(getTableIterator, Iterator*()); // TableIterator* createTableIterator();
        MOCK_METHOD1(getTable, RestaurantTable*(int)); // RestaurantTable* getTable(int index);
        MOCK_METHOD0(getWaiterSize, int()); // int getWaiterSize() const;
        MOCK_METHOD0(getTablesPerWaiter, int()); // int getTablesPerWaiter() const;
        MOCK_METHOD0(getTotalTables, int()); // int getTotalTables() const;
        MOCK_METHOD0(createTableIterator, TableIterator*()); // Iterator* getWaiterIterator();
        MOCK_METHOD0(createWaiterIterator, WaiterIterator*()); // Iterator* getTableIterator();
        MOCK_METHOD1(getMenuItem, MenuItem*(std::string)); // MenuItem* getMenuItem(std::string name);
        MOCK_METHOD1(getWaiter, void(RestaurantTable*)); // void getWaiter(RestaurantTable* table);
        MOCK_METHOD1(addTable, void(RestaurantTable*)); // void addTable(RestaurantTable* table);
        MOCK_METHOD1(addWaiter, void(Waiter*)); // void addWaiter(Waiter* waiter);
};

// TODO: Test extensively here (replaces main.cpp) such as control flows and exceptions

// * Test if all the members are properly initialized in the Facade class
TEST(FacadeConstructor, Constructor) {
    MockFacade* facade = new MockFacade();
    EXPECT_EQ(facade->getWaiterSize(), 4);
    EXPECT_EQ(facade->getTablesPerWaiter(), 3);
    EXPECT_EQ(facade->getTotalTables(), 12);

    // for (int i = 0; i < facade.getWaiterSize(); i++) { 
    //     EXPECT_EQ(facade.getWaiter(i), nullptr);
    // }
    // for (int i = 0; i < facade.getTotalTables(); i++) {
    //     EXPECT_EQ(facade.getTable(i), nullptr);
    // }
    
}