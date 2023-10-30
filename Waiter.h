#ifndef WAITER_H
#define WAITER_H
#include "WaiterState.h"

// Receiver (Command)
// Context (State)

class Waiter {
    public:
        Waiter(int id);
        void placeOrder();
        void cleanUp();
        void confirmOrder();
    private:
        WaiterState* state;
        int waiterId;
};

#endif // WAITER_H
