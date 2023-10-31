#ifndef WAITER_H
#define WAITER_H

// Receiver (Command)
// Context (State)

#include <iostream>

#include "WaiterState.h"
#include "WaiterIterator.h"
#include "Order.h"
#include "FloorColleague.h"

class Waiter {
    private:
        WaiterState* state;
        Order** orders;
        int busyOrders = 0;
        int totalOrders;
        FloorColleague* floorColleague;
    public:
        Waiter(int totalOrders, FloorColleague *fc);
        void setWaiterState(WaiterState* state);
        void addItem(RestaurantTable* rt, MenuItem* m);
        void cleanUp(RestaurantTable* rt);
        void confirmOrder(RestaurantTable* rt);
        void addOrder(Order* o);
        Order* getOrder(RestaurantTable* rt);
        bool isAvailable();
};

#endif // WAITER_H
