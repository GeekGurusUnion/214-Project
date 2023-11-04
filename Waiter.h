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
        std::vector<MenuItem*> menu = std::vector<MenuItem*>();
        Command* cO = nullptr;
        Command* tO = nullptr;
    public:
        Waiter(std::string name, int totalOrders, FloorColleague *fc);
        ~Waiter();
        void setWaiterState(WaiterState* state);
        void addItem(RestaurantTable* rt, std::string m);
        void confirmOrder(RestaurantTable* rt);
        void addOrder(RestaurantTable* rt);
        Order* getOrder(RestaurantTable* rt);
        bool isAvailable();
        std::string getName() const;
        MenuItem *getMenuItem(std::string name);

        int getBusyOrders() const;

        // * testing * //
            int getTotalOrders() const;
            WaiterState* getState() const;
            std::vector<RestaurantTable*> getTables() const;
            std::vector<MenuItem*> getMenu() const;
            Command* getCO() const;
            Command* getTO() const;
            void setState(WaiterState* state);
        // * end of testing * //
};

#endif // WAITER_H
