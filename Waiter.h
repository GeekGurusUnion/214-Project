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
        WaiterState* state;
        std::vector<RestaurantTable*> tables = std::vector<RestaurantTable*>();
        int busyOrders = 0;
        int totalOrders;
        FloorColleague* floorColleague;
        std::vector<MenuItem*> menu = std::vector<MenuItem*>();
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
        MenuItem *getMenuItem(std::string name);
        int getBusyOrders() const;
};

#endif // WAITER_H
