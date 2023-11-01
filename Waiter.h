#ifndef WAITER_H
#define WAITER_H

// Receiver (Command)
// Context (State)

#include <iostream>

#include "WaiterState.h"
#include "WaiterStateAvailable.h"
#include "WaiterStateUnavailable.h"
#include "WaiterIterator.h"
#include "Order.h"
#include "FloorColleague.h"

class Waiter {
    private:
        std::string name;
        WaiterState* state = new WaiterStateAvailable();
        std::vector<RestaurantTable*> tables = std::vector<RestaurantTable*>();
        int busyOrders = 0;
        int totalOrders;
        FloorColleague* floorColleague;
    public:
        Waiter(std::string name, int totalOrders, FloorColleague *fc);
        void setWaiterState(WaiterState* state);
        void addItem(RestaurantTable* rt, MenuItem* m);
        void cleanUp(RestaurantTable* rt);
        void confirmOrder(RestaurantTable* rt);
        void addOrder(RestaurantTable* rt);
        Order* getOrder(RestaurantTable* rt);
        bool isAvailable();
        std::string getName() const;
        int getBusyOrders() const;
};

#endif // WAITER_H
