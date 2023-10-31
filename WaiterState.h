#ifndef WAITER_STATE_H
#define WAITER_STATE_H

// State (State) [interface]

// #include "Waiter.h"

class Waiter;
#include <iostream>

// #include "WaiterStateAvailable.h"
// #include "WaiterStateUnavailable.h"

class WaiterState {
    protected:
        Waiter* waiter;
    public:
        void setWaiter(Waiter* waiter);
        virtual void isAvailable() = 0;
        virtual void isUnavailable() = 0;
};

#endif // WAITER_STATE_H