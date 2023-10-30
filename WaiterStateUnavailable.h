#ifndef WAITER_STATE_UNAVAILABLE_H
#define WAITER_STATE_UNAVAILABLE_H

// ConcreteState (State)

#include "WaiterState.h"

class WaiterUnavailable : public WaiterState {
    public:
        bool hasNext();
        void* next();
};

#endif // WAITER_STATE_UNAVAILABLE_H