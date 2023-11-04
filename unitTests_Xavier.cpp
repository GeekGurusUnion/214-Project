#include <iostream>
#include <vector>

//include the google test dependencies
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "WaiterIterator.h"
#include "Waiter.h"

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

// write more tests here
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
// write a test for getWaiter
// it should return true if the waiter is found in the iterator
TEST(WaiterIteratorTest, getWaiter) {
  std::vector<Waiter*> waiters;
  Waiter* waiter = new Waiter("John", 5, nullptr);
  waiters.push_back(waiter);
  MockWaiterIterator waiterIterator(waiters);
  EXPECT_CALL(waiterIterator, getWaiter("John")).Times(1).WillOnce(testing::Return(true));
  waiterIterator.getWaiter("John");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}