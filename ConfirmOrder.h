#ifndef CONFIRMORDER_H
#define CONFIRMORDER_H

// ConcreteCommand (Command)

#include "Command.h"
#include "Waiter.h"

class ConfirmOrder {
    public:
        ConfirmOrder(Waiter* waiter);
        void execute();
    private:
        Waiter* waiter;
};

#endif // CONFIRMORDER_H
