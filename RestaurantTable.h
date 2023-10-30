#ifndef RESTAURANT_TABLE_H_
#define RESTAURANT_TABLE_H_

// ConcreteSubject (Observer)
// Context (State)
// Invoker (Command)
// ConcreteAggregate (Iterator)

#include "StateEmpty.h"
#include "Table.h"
#include "Command.h"
#include "Waiter.h"
#include "TableIterator.h"
#include <iostream> 

class RestaurantTable : public Table {
    private:
        State* currentState;
        Command* cO;
        Command* cT;
        Command* tO;
        Waiter* waiter;
        TableIterator* tableIterator;
        int tableNumber;
        
    public:
        RestaurantTable(int i, Iterator* tableIterator);
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