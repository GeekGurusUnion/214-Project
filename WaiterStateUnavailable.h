#ifndef WAITER_STATE_UNAVAILABLE_H
#define WAITER_STATE_UNAVAILABLE_H

// ConcreteState (State)

#include "WaiterState.h"

class WaiterStateUnavailable : public WaiterState {
    public:
        bool isAvailable();
        bool isUnavailable();
        void setAvailable();
        void setUnavailable();
};

#endif // WAITER_STATE_UNAVAILABLE_H