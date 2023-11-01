#ifndef RESTAURANT_TABLE_H_
#define RESTAURANT_TABLE_H_

// ConcreteSubject (Observer)
// Context (State)
// Invoker (Command)
// ConcreteAggregate (Iterator)

#include "StateEmpty.h"

// #include "Table.h"

class Waiter;

class TableObserver;

// class Command;
// class ConfirmOrder;
// class CleanTable;
// class TakeOrder;

#include "Order.h"
class Order;

#include "ConfirmOrder.h"
#include "CleanTable.h"
#include "TakeOrder.h"

#include "TableObserver.h"

#include "TableIterator.h"
#include <iostream> 

class RestaurantTable {
    private:
        State* currentState = new StateEmpty();
        Waiter* waiter = nullptr;
        
        int tableNumber;
        Order* order;
        TableObserver* observer;
        
    public:
        RestaurantTable(int i);
        ~RestaurantTable();
        void TransitionTo(State *state);
        
        void setState(State* state);
        State* getState();

        void occupy();
        void empty();

        void notifyWaiter(std::string action, bool isItem); // assuming only one waiter helps a table
        
        Waiter* getWaiter() const;
        void setWaiter(Waiter* waiter);

        void confirmOrder();
        void welcomeWaiter();
        void cleanTable();
        void addToOrder(std::string item);

        Order* getOrder() const;

        bool isAvailable() const;

        int getTableNumber() const;
};

#endif  // RESTAURANT_TABLE_H_