#ifndef WAITER_STATE_UNAVAILABLE_H
#define WAITER_STATE_UNAVAILABLE_H

// ConcreteState (State)

#include "WaiterState.h"

class WaiterStateUnavailable : public WaiterState {
    public:
        void isAvailable();
        void isUnavailable();
};

#endif // WAITER_STATE_UNAVAILABLE_H