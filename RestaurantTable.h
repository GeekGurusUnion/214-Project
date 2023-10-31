#ifndef RESTAURANT_TABLE_H_
#define RESTAURANT_TABLE_H_

// ConcreteSubject (Observer)
// Context (State)
// Invoker (Command)
// ConcreteAggregate (Iterator)

#include "StateEmpty.h"
#include "Table.h"

#include "ConfirmOrder.h"
#include "CleanTable.h"
#include "TakeOrder.h"

#include "Waiter.h"
#include "TableIterator.h"
#include <iostream> 

class RestaurantTable : public Table {
    private:
        State* currentState = new StateEmpty();
        Waiter* waiter = nullptr;
        Command* cO = new ConfirmOrder(waiter);
        Command* cT = new CleanTable(waiter); 
        Command* tO = new TakeOrder(waiter);
        int tableNumber;
        
    public:
        RestaurantTable(int i);
        ~RestaurantTable();
        void TransitionTo(State *state);
        
        void setState(State* state);
        State* getState();

        void occupy();
        void empty();
        
        Waiter* getWaiter() const;
        void setWaiter(Waiter* waiter);
};

#endif  // RESTAURANT_TABLE_H_