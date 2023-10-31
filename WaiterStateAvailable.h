#ifndef WAITER__STATE_AVAILABLE_H
#define WAITER__STATE_AVAILABLE_H

// ConcreteState (State)

#include "WaiterState.h"

class WaiterStateAvailable : public WaiterState {
    public:
        void isAvailable();
        void isUnavailable();
};

#endif // WAITER__STATE_AVAILABLE_H