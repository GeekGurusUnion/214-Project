#ifndef RESTAURANT_TABLE_H_
#define RESTAURANT_TABLE_H_

// ConcreteSubject (Observer)
// Context (State)
// Invoker (Command)
// ConcreteAggregate (Iterator)

#include "StateEmpty.h"
#include "Table.h"
#include "Waiter.h"
#include <iostream> 

class RestaurantTable : public Table {
    public:
        RestaurantTable();
        ~RestaurantTable();
        void TransitionTo(State *state);
        void setState(State* state);
        void reserve();
        void occupy();
        void empty();
};

#endif  // RESTAURANT_TABLE_H_