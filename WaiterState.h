#ifndef WAITER_STATE_H
#define WAITER_STATE_H

class WaiterState {
    public:
        virtual bool hasNext() = 0;
        virtual void* next() = 0;
};

#endif // WAITER_STATE_H