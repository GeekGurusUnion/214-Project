#include <iostream>
#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Facade.h"

class MockWaiterIterator: public WaiterIterator {
    public:
        MockWaiterIterator(std::vector<Waiter*> waiters) : WaiterIterator(waiters) {};
        MOCK_METHOD0(hasNext, bool());
        // MOCK_METHOD0(next, Waiter*());
        // MOCK_METHOD1(isAvailable, bool(Waiter*));
        MOCK_METHOD0(reset, void());
};

class MockWaiter: public Waiter{
    public:
        MockWaiter(std::string name, int capacity, FloorColleague* fc) : Waiter(name, capacity, fc) {};
};

class MockTable: public RestaurantTable{
    public:
        MockTable(int tableNumber, int capacity) : RestaurantTable(tableNumber, capacity) {}
        MOCK_METHOD0(isAvailable, bool());
};

class MockObserver: public TableObserver {
    public:
    // observer->update(table, "split", "", false, this, count);
    MOCK_METHOD6(update, void(RestaurantTable*, std::string, std::string, bool, Facade*, double));        
};

class MockFacade : private Facade {
    public:        
        MockFacade() : Facade() {} // Facade();
        MOCK_METHOD1(getSeated, void(int));  // void getSeated();
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
        MOCK_METHOD1(setTablesPerWaiter, void(int)); // void setTablesPerWaiter(int tablesPerWaiter);
        MOCK_METHOD1(setWaiterSize, void(int)); // void setWaiterSize(int waiterSize);
        MOCK_METHOD1(setTotalTables, void(int)); // void setTotalTables(int totalTables);
        MOCK_METHOD1(setObserver, void(TableObserver*)); // void setObserver(TableObserver* observer);
        MOCK_METHOD1(setWaiterIterator, void(WaiterIterator*)); // void setWaiterIterator(WaiterIterator* waiterIterator);
        MOCK_METHOD1(generateBill, void(int)); // void generateBill(int tableNumber);
        MOCK_METHOD3(addCustomization, void(int, std::string, std::string)); // void addCustomization(int tableNumber, std::string itemName, std::string customization);
        MOCK_METHOD2(mergeTables, void(RestaurantTable*, int)); // void mergeTables(int tableNumber1, int tableNumber2);
        MOCK_METHOD2(tip, void(int, int)); // void tip(int tableNumber, int amount
        MOCK_METHOD2(splitBill, void(int, int)); // void splitBill(int tableNumber, int amount);
        MOCK_METHOD2(complain, void(int, std::string)); // void complain(int tableNumber, std::string complaint);
        MOCK_METHOD1(payBill, void(int)); // void payBill(int tableNumber);

};

// TODO: Test extensively here (replaces main.cpp) such as control flows and exceptions
// ! Facade tests ! //
// * Test if all the members are properly initialized in the Facade class
TEST(FacadeConstructor, Constructor) {
    MockFacade* facade = new MockFacade();
    EXPECT_EQ(facade->getWaiterSize(), 0);
    EXPECT_EQ(facade->getTablesPerWaiter(), 0);
    EXPECT_EQ(facade->getTotalTables(), 0);

    // for (int i = 0; i < facade.getWaiterSize(); i++) { 
    //     EXPECT_EQ(facade.getWaiter(i), nullptr);
    // }
    // for (int i = 0; i < facade.getTotalTables(); i++) {
    //     EXPECT_EQ(facade.getTable(i), nullptr);
    // }
    
}

//* test if getSeated works
TEST(FacadeSeats, getSeated) {
    MockFacade* facade = new MockFacade();
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    EXPECT_CALL(*facade, getSeated(1)).Times(1);
    EXPECT_CALL(*facade, getWaiter(testing::_)).Times(1);
    facade->getSeated(1);
}

TEST(FacadeOrder, addToOrder) {
    
    MockFacade* facade = new MockFacade();
    MockObserver* observer = new MockObserver();
    
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);

    // Set expectations for the addToOrder method of the MockFacade
    EXPECT_CALL(*facade, addToOrder(1, "test")).Times(1);
    EXPECT_CALL(*observer, update(testing::_,testing::_,testing::_,testing::_,testing::_,testing::_)).Times(1);
    // Call the method you want to test
    facade->addToOrder(1, "test");

    // delete facade;
}

TEST(FacadeOrder, confirmOrder) {
    MockFacade* facade = new MockFacade();
    MockObserver* observer = new MockObserver();
    
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);

    // Set expectations for the addToOrder method of the MockFacade
    EXPECT_CALL(*facade, confirmOrder(1)).Times(1);
    // observer->update(table, "confirm", "", false, this, 0);
    EXPECT_CALL(*observer, update(testing::_,testing::_,testing::_,testing::_,testing::_,testing::_)).Times(1);
    // Call the method you want to test
    facade->confirmOrder(1);

    
    // delete facade;
}

TEST(FacadeLeave, leaveTable) {
    MockFacade* facade = new MockFacade();
    // MockObserver* observer = new MockObserver();
    MockTable* table = new MockTable(1, 2);
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    facade->addTable(table);
    // Set expectations for the addToOrder method of the MockFacade
    EXPECT_CALL(*facade, leaveTable(2)).Times(1);
    EXPECT_CALL(*table, isAvailable()).Times(1).WillOnce(testing::Return(false));
    // Call the method you want to test
    facade->leaveTable(2);
    // delete table;
    // delete facade;
}
//simple getters
TEST(FacadeGetWaiter, getWaiter) {
    MockFacade* facade = new MockFacade();
    MockTable* table = new MockTable(1, 2);
    MockWaiter* waiter = new MockWaiter("John", 3, nullptr);
    std::vector<Waiter*> waitersin;
    waitersin.push_back(waiter);
    MockWaiterIterator* waiterIterator = new MockWaiterIterator(waitersin);
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    facade->addTable(table);
    facade->setWaiterIterator(waiterIterator);
    
    EXPECT_CALL(*facade, getWaiter(table)).Times(1);
    EXPECT_CALL(*waiterIterator, reset()).Times(1);
    facade->getWaiter(table);
    
    
}

TEST(FacadeBill,generateBill){
    MockFacade* facade = new MockFacade();
    MockObserver* observer = new MockObserver();
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    EXPECT_CALL(*facade, generateBill(1)).Times(1);
    EXPECT_CALL(*observer, update(testing::_,testing::_,testing::_,testing::_,testing::_,testing::_)).Times(1);
    facade->generateBill(1);
}

TEST(FacadeCustomization,addCustomization){
    MockFacade* facade = new MockFacade();
    MockObserver* observer = new MockObserver();
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    EXPECT_CALL(*facade, addCustomization(1,"test","test")).Times(1);
    EXPECT_CALL(*observer, update(testing::_,testing::_,testing::_,testing::_,testing::_,testing::_)).Times(1);
    facade->addCustomization(1,"test","test");
}

TEST(FacadeMerge,mergeTables){
    MockFacade* facade = new MockFacade();
    MockObserver* observer = new MockObserver();
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    EXPECT_CALL(*facade, mergeTables(nullptr,2)).Times(1);
    EXPECT_CALL(*observer, update(testing::_,testing::_,testing::_,testing::_,testing::_,testing::_)).Times(1);
    facade->mergeTables(nullptr,2);
}

TEST(FacadeTip,tip){
    MockFacade* facade = new MockFacade();
    MockObserver* observer = new MockObserver();
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    EXPECT_CALL(*facade, tip(1,2)).Times(1);
    EXPECT_CALL(*observer, update(testing::_,testing::_,testing::_,testing::_,testing::_,testing::_)).Times(1);
    facade->tip(1,2);
}


TEST(FacadeSplitBill,splitBill){
    MockFacade* facade = new MockFacade();
    MockObserver* observer = new MockObserver();
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    EXPECT_CALL(*facade, splitBill(1,2)).Times(1);
    EXPECT_CALL(*observer, update(testing::_,testing::_,testing::_,testing::_,testing::_,testing::_)).Times(1);
    facade->splitBill(1,2);
}

TEST(FacadeComplain, complain){
    MockFacade* facade = new MockFacade();
    MockObserver* observer = new MockObserver();
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    EXPECT_CALL(*facade, complain(1,"test")).Times(1);
    EXPECT_CALL(*observer, update(testing::_,testing::_,testing::_,testing::_,testing::_,testing::_)).Times(1);
    facade->complain(1,"test");
}

TEST(FacadePayBill, payBill){
    MockFacade* facade = new MockFacade();
    MockObserver* observer = new MockObserver();
    facade->setTablesPerWaiter(3);
    facade->setWaiterSize(4);
    facade->setTotalTables(12);
    EXPECT_CALL(*facade, payBill(1)).Times(1);
    EXPECT_CALL(*observer, update(testing::_,testing::_,testing::_,testing::_,testing::_,testing::_)).Times(1);
    facade->payBill(1);
}
//get table iterator

// add table

// add waiter

// get waiter iterator

//get table iterator

// get table

//get waiter size

// get tables per waiter

// get total tables

// create table iterator

// create waiter iterator
