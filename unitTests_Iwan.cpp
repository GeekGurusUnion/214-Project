#include <iostream>
#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Waiter.h"

class MockWaiter : public Waiter {
public:
    MockWaiter(std::string name, int totalOrders, FloorColleague* fc) : Waiter(name, totalOrders, fc) {}
    MOCK_METHOD0(getName, std::string());
};

class CallerClass {
    private:
        Waiter* w;
    public:
        explicit CallerClass(Waiter* w1) : w(w1) {}
        std::string getName() { return w->getName(); }
};

// TEST(myTest, testMyFunction) {
//     std::shared_ptr<Waiter> mockWaiter(new MockWaiter("Bob", 5, nullptr));
//     EXPECT_CALL(*std::static_pointer_cast<MockWaiter>(mockWaiter),
//         getName()).Times(testing::AtLeast(1));

//     CallerClass callerClass(mockWaiter.get());
//     callerClass.getName();
// }

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


// test waiter
// TEST(MockWaiter, waiterName) {
//     MockWaiter w("Bob", 5, nullptr);
//     EXPECT_EQ(w.getName(), "Bob") << "Waiter name not set correctly";
// }

TEST(MockWaiter, waiterName) {
    MockWaiter w("Bob", 5, nullptr);
    EXPECT_CALL(w, getName()).Times(1).WillOnce(testing::Return("Bob"));
    w.getName();
}

// TEST(WaiterTest, waiterStateSet) {
//     MockWaiter w("Bob", 5, nullptr);
//     WaiterState *ws = new WaiterStateAvailable(w);
//     w->setWaiterState(ws);
//     EXPECT_EQ(w->isAvailable(), true) << "Waiter state not set correctly";
// }
// TEST(WaiterTest, waiterAddItem) {
//     Waiter *w = new Waiter("Bob", 5, nullptr);
//     WaiterState *ws = new WaiterStateAvailable(w);
//     w->setWaiterState(ws);
//     RestaurantTable *rt = new RestaurantTable(1);
//     rt->setWaiter(w);
//     w->addOrder(rt);
//     w->addItem(rt, "Burger");
//     EXPECT_EQ(w->getOrder(rt)->getOrderSize(), 1) << "Waiter did not add item correctly";
// }
// TEST(WaiterTest, waiterStateSet) {
//     MockWaiter w("Bob", 5, nullptr);
//     WaiterState *ws = new WaiterStateAvailable(&w);
//     EXPECT_CALL(w, setWaiterState(ws)).Times(1);
//     w.setWaiterState(ws);
// }
// TEST(WaiterTest, waiterConfirmOrder) {
//     MockWaiter w("Bob", 5, nullptr);
//     WaiterState *ws = new WaiterStateAvailable(&w);
//     RestaurantTable *rt = new RestaurantTable(1);
//     rt->setWaiter(&w);
//     w.addOrder(rt);
//     w.addItem(rt, "Burger");
//     w.setWaiterState(ws);
//     EXPECT_CALL(w, confirmOrder(rt)).Times(1);
//     w.confirmOrder(rt);
// }


