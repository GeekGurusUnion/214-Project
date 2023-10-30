#ifndef WAITER_H
#define WAITER_H

// Receiver (Command)
// Context (State)

#include "WaiterState.h"
#include "WaiterIterator.h"

class Waiter {
    public:
        Waiter(Iterator* waiterIterator);
        void placeOrder();
        void cleanUp();
        void confirmOrder();
    private:
        WaiterState* state;
        int waiterId;
};

#endif // WAITER_H
