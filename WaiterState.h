#ifndef WAITER_STATE_H
#define WAITER_STATE_H

// State (State) [interface]

class WaiterState {
    public:
        virtual bool hasNext() = 0;
        virtual void* next() = 0;
};

#endif // WAITER_STATE_H