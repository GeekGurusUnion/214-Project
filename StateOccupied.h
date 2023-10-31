#ifndef STATE_OCCUPIED_H_
#define STATE_OCCUPIED_H_

// ConcreteState (State)

#include "State.h"
#include <iostream> 

class RestaurantTable;

class StateOccupied : public State {
    public:
        StateOccupied();
        void serve();
        void occupy();
        void empty();
        std::string getStateName();
        bool isOccupied();
};

#endif  // STATE_OCCUPIED_H_