#include <iostream>
#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Waiter.h"
class MockWaiter : public Waiter {
    public:
        MockWaiter(std::string name, int totalOrders, FloorColleague* fc) : Waiter(name, totalOrders, fc) {}
        MOCK_METHOD0(Die, void());
        MOCK_METHOD1(setWaiterState, void(WaiterState*));
        MOCK_METHOD2(addItem, void(RestaurantTable*, std::string));
        MOCK_METHOD1(confirmOrder, void(RestaurantTable*));
        MOCK_METHOD1(addOrder, void(RestaurantTable*));
        MOCK_METHOD1(getOrder, Order*(RestaurantTable*));
        MOCK_METHOD0(isAvailable, bool());
        MOCK_METHOD0(getName, std::string());
        MOCK_METHOD1(getMenuItem, MenuItem*(std::string));
        MOCK_METHOD0(getBusyOrders, int());

        // * testing //
        MOCK_METHOD0(getTotalOrders, int());
        MOCK_METHOD0(getState, WaiterState*());
        MOCK_METHOD0(getTables, std::vector<RestaurantTable*>());
        MOCK_METHOD0(getMenu, std::vector<MenuItem*>());
        MOCK_METHOD0(getCO, Command*());
        MOCK_METHOD0(getTO, Command*());
        // * end of testing //
};

class MockWaiterStateAvailable : public WaiterStateAvailable {
    public:
        MockWaiterStateAvailable(Waiter* waiter) : WaiterStateAvailable(waiter) {}
        MOCK_METHOD0(isAvailable, bool());
        MOCK_METHOD0(isUnavailable, bool());
        MOCK_METHOD0(setAvailable, void());
        MOCK_METHOD0(setUnavailable, void());

        // * testing //
        MOCK_METHOD0(getWaiter, Waiter*());
        MOCK_METHOD0(getThis, WaiterState*());
        // * end of testing //
};

class MockWaiterStateUnavailable : public WaiterStateUnavailable {
    public:
        MockWaiterStateUnavailable(Waiter* waiter) : WaiterStateUnavailable(waiter) {}
        MOCK_METHOD0(isAvailable, bool());
        MOCK_METHOD0(isUnavailable, bool());
        MOCK_METHOD0(setAvailable, void());
        MOCK_METHOD0(setUnavailable, void());

        // * testing //
        MOCK_METHOD0(getWaiter, Waiter*());
        MOCK_METHOD0(getThis, WaiterState*());
        // * end of testing //
};

class MockConfirmOrder : public ConfirmOrder {
    public:
        MockConfirmOrder(Waiter* waiter) : ConfirmOrder(waiter, nullptr) {}
        MOCK_METHOD0(execute, void());
        MOCK_METHOD0(getWaiter, Waiter*());
};

class MockTakeOrder : public TakeOrder {
    public:
        MockTakeOrder(Waiter* waiter) : TakeOrder(waiter) {}
        MOCK_METHOD0(execute, void());
        MOCK_METHOD0(getWaiter, Waiter*());
};

#include "StateEmpty.h"
#include "StateServe.h"
#include "StateOccupied.h"   

class MockStateEmpty : public StateEmpty {
    public:
        MockStateEmpty(RestaurantTable* rt) : StateEmpty(rt) {}
        MOCK_METHOD0(isEmpty, bool());
        MOCK_METHOD0(isOccupied, bool());
        MOCK_METHOD0(isServed, bool());
        MOCK_METHOD0(setEmpty, void());
        MOCK_METHOD0(setOccupied, void());
        MOCK_METHOD0(setServed, void());
        MOCK_METHOD0(getThis, State*());
};

class MockStateServe : public StateServe {
    public:
        MockStateServe(RestaurantTable* rt) : StateServe(rt) {}
        MOCK_METHOD0(isEmpty, bool());
        MOCK_METHOD0(isOccupied, bool());
        MOCK_METHOD0(isServed, bool());
        MOCK_METHOD0(setEmpty, void());
        MOCK_METHOD0(setOccupied, void());
        MOCK_METHOD0(setServed, void());
        MOCK_METHOD0(getThis, State*());
};

class MockStateOccupied : public StateOccupied {
    public:
        MockStateOccupied(RestaurantTable* rt) : StateOccupied(rt) {}
        MOCK_METHOD0(isEmpty, bool());
        MOCK_METHOD0(isOccupied, bool());
        MOCK_METHOD0(isServed, bool());
        MOCK_METHOD0(setEmpty, void());
        MOCK_METHOD0(setOccupied, void());
        MOCK_METHOD0(setServed, void());
        MOCK_METHOD0(getThis, State*());
};

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// ! WaiterTests ! //
// * Test if waiter name gets set in constructor
TEST(WaiterTests, waiterName) {
    MockWaiter w("Bob", 5, nullptr);
    EXPECT_CALL(w, getName()).Times(1).WillOnce(testing::Return("Bob"));
    w.getName();
}

// * Test destructor 
TEST(WaiterTests, waiterDestructor) {
    MockWaiter w("Bob", 5, nullptr);
    EXPECT_CALL(w, Die());
    w.Die();
}

// * Test if waiter busyOrders gets set in constructor
TEST(WaiterTests, waiterBusyOrders) {
    MockWaiter w("Bob", 5, nullptr);
    EXPECT_CALL(w, getBusyOrders()).Times(1).WillOnce(testing::Return(0));
    w.getBusyOrders();
}

// * Test if waiter totalOrders gets set in constructor
TEST(WaiterTests, waiterTotalOrders) {
    MockWaiter w("Bob", 5, nullptr);
    EXPECT_CALL(w, getTotalOrders()).Times(1).WillOnce(testing::Return(5));
    w.getTotalOrders();
}

// * Test if waiter adds item to order
TEST(WaiterTests, waiterAddItem) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    RestaurantTable *rt = new RestaurantTable(1);
    rt->setWaiter(&w);
    EXPECT_CALL(w, addItem(rt, "Burger")).Times(1);
    w.addItem(rt, "Burger");
}

// * Test if waiter is available
TEST(WaiterTests, waiterStateSet) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    EXPECT_CALL(w, setWaiterState(ws)).Times(1);
    w.setWaiterState(ws);
}

// * Test if waiter adds item to order
TEST(WaiterTests, waiterConfirmOrder) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    RestaurantTable *rt = new RestaurantTable(1);
    rt->setWaiter(&w);
    EXPECT_CALL(w, confirmOrder(rt)).Times(1);
    w.confirmOrder(rt);
}

// * Test if waiter adds order
TEST(WaiterTests, waiterAddOrder) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    RestaurantTable *rt = new RestaurantTable(1);
    rt->setWaiter(&w);
    EXPECT_CALL(w, addOrder(rt)).Times(1);
    w.addOrder(rt);
}

// * Test if waiter gets order
TEST(WaiterTests, waiterGetOrder) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    RestaurantTable *rt = new RestaurantTable(1);
    rt->setWaiter(&w);
    EXPECT_CALL(w, getOrder(rt)).Times(1);
    w.getOrder(rt);
}

// * Test if waiter is available
TEST(WaiterTests, waiterIsAvailable) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    EXPECT_CALL(w, isAvailable()).Times(1);
    w.isAvailable();
}

// * Test if waiter gets menu item
TEST(WaiterTests, waiterGetMenuItem) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    EXPECT_CALL(w, getMenuItem("Burger")).Times(1);
    w.getMenuItem("Burger");
}

// * Test if waiter gets state
TEST(WaiterTests, waiterGetState) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    EXPECT_CALL(w, getState()).Times(1);
    w.getState();
}

// * Test if waiter gets tables
TEST(WaiterTests, waiterGetTables) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    EXPECT_CALL(w, getTables()).Times(1);
    w.getTables();
}

// * Test if waiter gets menu
TEST(WaiterTests, waiterGetMenu) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterState *ws = new WaiterStateAvailable(&w);
    EXPECT_CALL(w, getMenu()).Times(1);
    w.getMenu();
}

// * Test if waiter gets CO
TEST(WaiterTests, waiterGetCO) {
    MockWaiter w("Bob", 5, nullptr);
    EXPECT_CALL(w, getCO()).Times(1);
    w.getCO();
}

// * Test if waiter gets TO
TEST(WaiterTests, waiterGetTO) {
    MockWaiter w("Bob", 5, nullptr);
    EXPECT_CALL(w, getTO()).Times(1);
    w.getTO();
}
// ! WaiterTests End ! //

// ! WaiterState Tests ! //
// * Test if waiter state is available
TEST(WaiterStateTests, waiterStateIsAvailable) {
    MockWaiter w("Bob", 5, nullptr);
    MockWaiterStateAvailable ws(&w);
    EXPECT_CALL(ws, isAvailable()).Times(1).WillOnce(testing::Return(true));
    ws.isAvailable();
}

// * Test if waiter state is unavailable
TEST(WaiterStateTests, waiterStateIsUnavailable) {
    MockWaiter w("Bob", 5, nullptr);
    MockWaiterStateAvailable ws(&w);
    EXPECT_CALL(ws, isUnavailable()).Times(1).WillOnce(testing::Return(false));
    ws.isUnavailable();
}

// * Test if waiter state is set to available
TEST(WaiterStateTests, waiterStateSetAvailable) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterStateAvailable ws(&w);

    ws.setAvailable();
    EXPECT_TRUE(ws.isAvailable());
}

// * Test if waiter state is set to unavailable
TEST(WaiterStateTests, waiterStateSetUnavailable) {
    MockWaiter w("Bob", 5, nullptr);
    WaiterStateUnavailable ws(&w);

    ws.setUnavailable();
    EXPECT_TRUE(ws.isUnavailable());
}

// * Test if waiter state gets waiter
TEST(WaiterStateTests, waiterStateGetWaiter) {
    MockWaiter w("Bob", 5, nullptr);
    MockWaiterStateAvailable ws(&w);
    EXPECT_CALL(ws, getWaiter()).Times(1).WillOnce(testing::Return(&w));
    ws.getWaiter();
}

// * Test if waiter state gets this
TEST(WaiterStateTests, waiterStateGetThis) {
    MockWaiter w("Bob", 5, nullptr);
    MockWaiterStateAvailable ws(&w);
    EXPECT_CALL(ws, getThis()).Times(1).WillOnce(testing::Return(&ws));
    ws.getThis();
}
// ! WaiterState Tests End ! //

// ! ConfirmOrder Tests ! //
// * Test if confirm order executes
TEST(ConfirmOrderTests, confirmOrderExecute) {
    MockWaiter w("Bob", 5, nullptr);
    MockConfirmOrder co(&w);
    EXPECT_CALL(co, execute()).Times(1);
    co.execute();
}

// * Test if confirm order gets waiter
TEST(ConfirmOrderTests, confirmOrderGetWaiter) {
    MockWaiter w("Bob", 5, nullptr);
    MockConfirmOrder co(&w);
    EXPECT_CALL(co, getWaiter()).Times(1).WillOnce(testing::Return(&w));
    co.getWaiter();
}
// ! ConfirmOrder Tests End ! //

// ! TakeOrder Tests ! //
// * Test if take order executes
TEST(TakeOrderTests, takeOrderExecute) {
    MockWaiter w("Bob", 5, nullptr);
    MockTakeOrder to(&w);
    EXPECT_CALL(to, execute()).Times(1);
    to.execute();
}

TEST(TakeOrderTests, takeOrderGetWaiter) {
    MockWaiter w("Bob", 5, nullptr);
    MockTakeOrder to(&w);
    EXPECT_CALL(to, getWaiter()).Times(1).WillOnce(testing::Return(&w));
    to.getWaiter();
}
// ! TakeOrder Tests End ! //

// ! EmptyState Tests ! //
// * Test if empty state is empty
TEST(EmptyStateTests, emptyStateIsEmpty) {
    MockWaiter w("Bob", 5, nullptr);
    MockStateEmpty es(nullptr);
    EXPECT_CALL(es, isEmpty()).Times(1).WillOnce(testing::Return(true));
    es.isEmpty();
}

// * Test if empty state is occupied
TEST(EmptyStateTests, emptyStateIsOccupied) {
    MockWaiter w("Bob", 5, nullptr);
    MockStateEmpty es(nullptr);
    EXPECT_CALL(es, isOccupied()).Times(1).WillOnce(testing::Return(false));
    es.isOccupied();
}

// * Test if empty state is served
TEST(EmptyStateTests, emptyStateIsServed) {
    MockWaiter w("Bob", 5, nullptr);
    MockStateEmpty es(nullptr);
    EXPECT_CALL(es, isServed()).Times(1).WillOnce(testing::Return(false));
    es.isServed();
}
// ! EmptyState Tests End ! //

// ! ServeState Tests ! //
// * Test if serve state is empty
TEST(ServeStateTests, serveStateIsEmpty) {
    MockWaiter w("Bob", 5, nullptr);
    MockStateServe ss(nullptr);
    EXPECT_CALL(ss, isEmpty()).Times(1).WillOnce(testing::Return(false));
    ss.isEmpty();
}

// * Test if serve state is occupied
TEST(ServeStateTests, serveStateIsOccupied) {
    MockWaiter w("Bob", 5, nullptr);
    MockStateServe ss(nullptr);
    EXPECT_CALL(ss, isOccupied()).Times(1).WillOnce(testing::Return(true));
    ss.isOccupied();
}

// * Test if serve state is served
TEST(ServeStateTests, serveStateIsServed) {
    MockWaiter w("Bob", 5, nullptr);
    MockStateServe ss(nullptr);
    EXPECT_CALL(ss, isServed()).Times(1).WillOnce(testing::Return(false));
    ss.isServed();
}
// ! ServeState Tests End ! //

// ! OccupiedState Tests ! //
// * Test if occupied state is empty
TEST(OccupiedStateTests, occupiedStateIsEmpty) {
    MockWaiter w("Bob", 5, nullptr);
    MockStateOccupied os(nullptr);
    EXPECT_CALL(os, isEmpty()).Times(1).WillOnce(testing::Return(false));
    os.isEmpty();
}

// * Test if occupied state is occupied
TEST(OccupiedStateTests, occupiedStateIsOccupied) {
    MockWaiter w("Bob", 5, nullptr);
    MockStateOccupied os(nullptr);
    EXPECT_CALL(os, isOccupied()).Times(1).WillOnce(testing::Return(false));
    os.isOccupied();
}

// * Test if occupied state is served
TEST(OccupiedStateTests, occupiedStateIsServed) {
    MockWaiter w("Bob", 5, nullptr);
    MockStateOccupied os(nullptr);
    EXPECT_CALL(os, isServed()).Times(1).WillOnce(testing::Return(true));
    os.isServed();
}
// ! OccupiedState Tests End ! //