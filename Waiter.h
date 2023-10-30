#ifndef WAITER_H_
#define WAITER_H_

class Waiter {
    public:
        Waiter(int id);
        void placeOrder();
        void cleanUp();
        void confirmOrder();
    private:
        int waiterId;
};

#endif // WAITER_H_