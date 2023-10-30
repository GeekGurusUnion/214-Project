#ifndef WAITER__STATE_AVAILABLE_H
#define WAITER__STATE_AVAILABLE_H

// ConcreteState (State)

#include "WaiterState.h"

class WaiterAvailable : public WaiterState {
    public:
        bool hasNext();
        void* next();
};

#endif // WAITER__STATE_AVAILABLE_H