#ifndef WAITER__STATE_AVAILABLE_H
#define WAITER__STATE_AVAILABLE_H

// ConcreteState (State)

#include "WaiterState.h"

class WaiterStateAvailable : public WaiterState {
    public:
        WaiterStateAvailable(Waiter* waiter);
        bool isAvailable();
        bool isUnavailable();
        void setAvailable();
        void setUnavailable();
};

#endif // WAITER__STATE_AVAILABLE_H