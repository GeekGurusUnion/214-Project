#ifndef STATE_RESERVED_H_
#define STATE_RESERVED_H_

// ConcreteState (State)

#include "State.h"
#include <iostream> 

class StateServe : public State {
    public:
        void serve();
        void occupy();
        void empty();
        std::string getStateName();
};

#endif  // STATE_RESERVED_H_