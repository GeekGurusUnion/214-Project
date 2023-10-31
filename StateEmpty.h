#ifndef STATE_EMPTY_H_
#define STATE_EMPTY_H_

// ConcreteState (State)

#include "State.h"
#include <iostream> 

class StateEmpty : public State {
    public:
        void serve();
        void occupy();
        void empty();
        std::string getStateName();
};

#endif  // STATE_EMPTY_H_