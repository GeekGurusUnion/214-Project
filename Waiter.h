#ifndef WAITER_H
#define WAITER_H

// Receiver (Command)
// Context (State)

class Waiter {
    public:
        Waiter(int id);
        void placeOrder();
        void cleanUp();
        void confirmOrder();
    private:
        int waiterId;
};

#endif // WAITER_H
