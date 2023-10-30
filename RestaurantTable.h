#ifndef RESTAURANT_TABLE_H_
#define RESTAURANT_TABLE_H_

// ConcreteSubject (Observer)
// Context (State)
// Invoker (Command)
// ConcreteAggregate (Iterator)

#include "StateEmpty.h"
#include "Table.h"
#include "Command.h"
#include <iostream> 

class RestaurantTable : public Table {
    private:
        State* currentState;
        Command* cO;
        Command* cT;
        Command* tO;
        Waiter* waiter;

    public:
        RestaurantTable();
        ~RestaurantTable();
        void TransitionTo(State *state);
        void setState(State* state);
        void placeOrder();
        void confirmOrder();
        void cleanTable();
};

#endif  // RESTAURANT_TABLE_H_