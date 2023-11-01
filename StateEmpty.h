#ifndef STATE_EMPTY_H_
#define STATE_EMPTY_H_

// ConcreteState (State)

#include "State.h"
#include <iostream> 

class StateEmpty : public State {
    public:
        StateEmpty(RestaurantTable* table);
        void serve();
        void occupy();
        void empty();
        std::string getStateName();
        bool isOccupied();
};

#endif  // STATE_EMPTY_H_