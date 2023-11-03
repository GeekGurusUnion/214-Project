#ifndef WAITER_STATE_H
#define WAITER_STATE_H

// State (State) [interface]

class Waiter;
#include <iostream>

class Waiter;

class WaiterState {
    protected:
        Waiter* waiter;
    public:
        WaiterState(Waiter* waiter);
        virtual ~WaiterState() {};
        void setWaiter(Waiter* waiter);
        virtual void setAvailable() = 0;
        virtual void setUnavailable() = 0;
        virtual bool isAvailable() = 0;
        virtual bool isUnavailable() = 0;
};

#endif // WAITER_STATE_H