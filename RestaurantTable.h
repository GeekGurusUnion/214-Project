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

#include "Order.h"
class Order;

#include "ConfirmOrder.h"
#include "TakeOrder.h"
#include "GenerateBill.h"
#include "CustomizeOrder.h"

#include "TableObserver.h"

#include "TableIterator.h"
#include <iostream> 

class RestaurantTable {
    private:
        State* currentState;
        Waiter* waiter = nullptr;
        int tableNumber;
        int tableSize;
        Order* order;
        
    public:
        RestaurantTable(int i, int t);
        ~RestaurantTable();
        void setState(State* state);
        State* getState();
        void occupy();
        void empty();
        void notifyWaiter(std::string action, bool isItem); // assuming only one waiter helps a table
        Waiter* getWaiter() const;
        void setWaiter(Waiter* waiter);
        void confirmOrder();
        void welcomeWaiter();
        void addToOrder(std::string item);
        Order* getOrder() const;
        bool isAvailable() const;
        int getTableNumber() const;
        float calculateBill();
        void printBill();
        int getTableSize();
};

#endif  // RESTAURANT_TABLE_H_