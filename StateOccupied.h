#ifndef STATE_OCCUPIED_H_
#define STATE_OCCUPIED_H_

// ConcreteState (State)

#include "State.h"
#include <iostream> 

class StateOccupied : public State {
    public:
        void serve();
        void occupy();
        void empty();
        std::string getStateName();
};

#endif  // STATE_OCCUPIED_H_