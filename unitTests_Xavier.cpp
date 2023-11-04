#include <iostream>
#include <vector>

//include the google test dependencies
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// header files for the waiters and the waiter iterator
#include "WaiterIterator.h"
#include "Waiter.h"

// header files for the tables and the table iterator
#include "TableIterator.h"
#include "RestaurantTable.h"

class MockTableIterator: public TableIterator {
public:
  MockTableIterator(std::vector<RestaurantTable*> tables) : TableIterator(tables) {};
  MOCK_METHOD0(first, void*());
  MOCK_METHOD0(currentItem, RestaurantTable*());
  MOCK_METHOD0(hasNext, bool());
  MOCK_METHOD0(next, void*());
  MOCK_METHOD1(isAvailable, bool(RestaurantTable* table));
  MOCK_METHOD0(reset, void());
};

class MockWaiterIterator: public WaiterIterator {
public:
  MockWaiterIterator(std::vector<Waiter*> waiters) : WaiterIterator(waiters) {};
  MOCK_METHOD0(first, void*());
  MOCK_METHOD0(currentItem, Waiter*());
  MOCK_METHOD0(hasNext, bool());
  MOCK_METHOD0(next, void*());
  MOCK_METHOD1(isAvailable, bool(Waiter* waiter));
  MOCK_METHOD0(reset, void());
  MOCK_METHOD1(getWaiter, bool (std::string name));
};

//* ------------- WaiterIterator tests -------------
TEST(WaiterIteratorTest, first) {
  std::vector<Waiter*> waiters;
  Waiter* waiter = new Waiter("John", 5, nullptr);
  waiters.push_back(waiter);
  MockWaiterIterator waiterIterator(waiters);
  EXPECT_CALL(waiterIterator, first()).Times(1).WillOnce(testing::Return(waiter));
  waiterIterator.first();
  delete waiter;
}

TEST(WaiterIteratorTest, currentItem) {
  std::vector<Waiter*> waiters;
  Waiter* waiter = new Waiter("John", 5, nullptr);
  waiters.push_back(waiter);
  MockWaiterIterator waiterIterator(waiters);
  EXPECT_CALL(waiterIterator, currentItem()).Times(1);
  waiterIterator.currentItem();
}

TEST(WaiterIteratorTest, hasNext) {
  std::vector<Waiter*> waiters;
  Waiter* waiter = new Waiter("John", 5, nullptr);
  waiters.push_back(waiter);
  MockWaiterIterator waiterIterator(waiters);
  EXPECT_CALL(waiterIterator, hasNext()).Times(1);
  waiterIterator.hasNext();
}

TEST(WaiterIteratorTest, next) {
  std::vector<Waiter*> waiters;
  Waiter* waiter = new Waiter("John", 5, nullptr);
  waiters.push_back(waiter);
  MockWaiterIterator waiterIterator(waiters);
  EXPECT_CALL(waiterIterator, next()).Times(1);
  waiterIterator.next();
}

TEST(WaiterIteratorTest, isAvailable) {
  std::vector<Waiter*> waiters;
  Waiter* waiter = new Waiter("John", 5, nullptr);
  waiters.push_back(waiter);
  MockWaiterIterator waiterIterator(waiters);
  EXPECT_CALL(waiterIterator, isAvailable(waiter)).Times(1).WillOnce(testing::Return(true));
  waiterIterator.isAvailable(waiter);
}

TEST(WaiterIteratorTest, reset) {
  std::vector<Waiter*> waiters;
  Waiter* waiter = new Waiter("John", 5, nullptr);
  waiters.push_back(waiter);
  MockWaiterIterator waiterIterator(waiters);
  EXPECT_CALL(waiterIterator, reset()).Times(1);
  waiterIterator.reset();
}

TEST(WaiterIteratorTest, AllWaitersAvailable) {
  std::vector<Waiter*> waiters;
  waiters.push_back(new Waiter("John", 5, nullptr));
  waiters.push_back(new Waiter("Jack", 5, nullptr));
  waiters.push_back(new Waiter("Jane", 5, nullptr));
  waiters.push_back(new Waiter("Jill", 5, nullptr));

  MockWaiterIterator waiterIterator(waiters);

  EXPECT_CALL(waiterIterator, getWaiter("John")).Times(1).WillOnce(testing::Return(true));
  EXPECT_CALL(waiterIterator, getWaiter("Jack")).Times(1).WillOnce(testing::Return(true));
  EXPECT_CALL(waiterIterator, getWaiter("Jane")).Times(1).WillOnce(testing::Return(true));
  EXPECT_CALL(waiterIterator, getWaiter("Jill")).Times(1).WillOnce(testing::Return(true));

  ASSERT_TRUE(waiterIterator.getWaiter("John"));
  ASSERT_TRUE(waiterIterator.getWaiter("Jack"));
  ASSERT_TRUE(waiterIterator.getWaiter("Jane"));
  ASSERT_TRUE(waiterIterator.getWaiter("Jill"));
}
//* ------------- WaiterIterator tests end -------------

//* ------------- TableIterator tests -------------
TEST(TableIteratorTest, first) {
  std::vector<RestaurantTable*> tables;
  RestaurantTable* table = new RestaurantTable(1);
  tables.push_back(table);
  MockTableIterator tableIterator(tables);
  EXPECT_CALL(tableIterator, first()).Times(1).WillOnce(testing::Return(table));
  tableIterator.first();
  delete table;
}

TEST(TableIteratorTest, currentItem) {
  std::vector<RestaurantTable*> tables;
  RestaurantTable* table = new RestaurantTable(1);
  tables.push_back(table);
  MockTableIterator tableIterator(tables);
  EXPECT_CALL(tableIterator, currentItem()).Times(1);
  tableIterator.currentItem();
}

TEST(TableIteratorTest, hasNext) {
  std::vector<RestaurantTable*> tables;
  RestaurantTable* table = new RestaurantTable(1);
  tables.push_back(table);
  MockTableIterator tableIterator(tables);
  EXPECT_CALL(tableIterator, hasNext()).Times(1);
  tableIterator.hasNext();
}

TEST(TableIteratorTest, next) {
  std::vector<RestaurantTable*> tables;
  RestaurantTable* table = new RestaurantTable(1);
  tables.push_back(table);
  MockTableIterator tableIterator(tables);
  EXPECT_CALL(tableIterator, next()).Times(1);
  tableIterator.next();
}

TEST(TableIteratorTest, isAvailable) {
  std::vector<RestaurantTable*> tables;
  RestaurantTable* table = new RestaurantTable(1);
  tables.push_back(table);
  MockTableIterator tableIterator(tables);
  EXPECT_CALL(tableIterator, isAvailable(table)).Times(1).WillOnce(testing::Return(true));
  tableIterator.isAvailable(table);
}

TEST(TableIteratorTest, reset) {
  std::vector<RestaurantTable*> tables;
  RestaurantTable* table = new RestaurantTable(1);
  tables.push_back(table);
  MockTableIterator tableIterator(tables);
  EXPECT_CALL(tableIterator, reset()).Times(1);
  tableIterator.reset();
}
//* ------------- TableIterator tests end -------------

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}