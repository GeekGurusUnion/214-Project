#include <iostream>
#include<memory>

//include the google test dependencies
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ConcreteMediator.h"
#include "FloorColleague.h"
#include "KitchenColleague.h"
#include "Order.h"
class MockMediator : public Mediator {
public:
  MockMediator() : Mediator() {}
  MOCK_METHOD1(addColleague, void(Colleague*));
  MOCK_METHOD1(notify, void(Colleague*));
};
class MockOrder: public Order{
  public:
    MockOrder(RestaurantTable* table) : Order(table){}
    MOCK_METHOD1(addItem, void(MenuItem*));
    MOCK_METHOD1(setStatus, void(bool));
    MOCK_METHOD1(removeItem, void(std::string));
    MOCK_METHOD0(getTable, RestaurantTable*());
    MOCK_METHOD0(getItems, std::vector<MenuItem*>());
    MOCK_METHOD2(addCustomization, void(std::string, std::string));
    MOCK_METHOD0(getOrderSize, int());
};
//mock colleague
class MockFloor : public Colleague {
  public:
    //it should take in the mock mediator
    MockFloor(MockMediator* mediator) : Colleague(mediator) {}
    MOCK_METHOD0(changed, void());
    MOCK_METHOD1(setOrder, void(Order*));
    MOCK_METHOD0(getOrder, Order*());
};
class MockKitchen : public Colleague {
  public:
    //it should take in the mock mediator
    MockKitchen(MockMediator* mediator) : Colleague(mediator) {}
    MOCK_METHOD0(changed, void());
    MOCK_METHOD1(setOrder, void(Order*));
    MOCK_METHOD0(getOrder, Order*());
};
// ! Mediator Test Begin  ! //

// * create mediator
TEST(MockMediator, createMediator) {
  MockMediator m;
};

// * add colleagues to the mediator
TEST(MockMediator, addColleague) {
  MockMediator* m = new MockMediator();
  Colleague *c1 = new MockFloor(m);
  Colleague *c2 = new MockKitchen(m);
  EXPECT_CALL(*m, addColleague(c1)).Times(1);
  EXPECT_CALL(*m, addColleague(c2)).Times(1);
  m->addColleague(c1);
  m->addColleague(c2);
  delete m;
  delete c1;
  delete c2;
};

// * notify from mediator
TEST(MockMediator, notifyFromMediator) {

  MockMediator* mediator = new MockMediator();
  MockFloor *colleague1 = new MockFloor(mediator);
  MockKitchen *colleague2 = new MockKitchen(mediator);

  // Add the mock colleagues to the mediator.
  mediator->addColleague(colleague1);
  mediator->addColleague(colleague2);

  // Create an order.
  Order* order = new Order(NULL);

  // Set the order of colleague1.
  colleague1->setOrder(order);

  // Notify the colleagues.
  mediator->notify(colleague1);

  // Create a new variable to store the order of colleague2.
  Order* colleague2Order = colleague2->getOrder();

  // Verify that the order of colleague2 is the same as the order that was set.
  EXPECT_EQ(colleague2Order, order);

  delete mediator;
  delete colleague1;
  delete colleague2;
}

// * notfiy from Colleague
TEST(MockMediator, notifyFromColleague) {
  MockMediator* m = new MockMediator();
  MockFloor *c1 = new MockFloor(m);
  // m->addColleague(c1);

  // Create an order.
  Order* order = new Order(NULL);

  // Set the order of the mock colleague.
  c1->setOrder(order);

  // Set an expectation that the setOrder() method of the mock colleague will be called once.
  EXPECT_CALL(*c1, setOrder(order)).Times(1);

  // Call the changed() method on the mock colleague.
  c1->changed();

  // Verify that the order of the mock colleague is the same as the order that was set.
  EXPECT_EQ(c1->getOrder(), order);

  delete m;
  delete c1;
}

// ! Mediator Test End ! //

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//declare the function(s) that you are testing
// double summer(double[], int);

// //our first unit test
// TEST(IntegerInputsSuite, simpleSum)
// {
//   //first, set up any inputs to your 
//   const int SIZE = 3;
//   double arr[SIZE]  = {1, 2, 3};
//   //then, make an assertion to test
//   EXPECT_EQ(summer(arr, SIZE), 6) << "The sum is not correct";
// }
// TEST(IntegerInputsSuite, oneElement)
// {
//   const int SIZE = 1;
//   double arr[SIZE]  = {33};
//   EXPECT_EQ(summer(arr, SIZE), 33) << "The sum is not correct for array of size 1";
// }
// TEST(DoubleInputsSuite, simpleSum)
// {
//   const int SIZE = 3;
//   double arr[SIZE]  = {1.1, 1.1, 1};
//   EXPECT_EQ(summer(arr, SIZE), 3.2) << "The sum is not correct using     double inputs";
// }