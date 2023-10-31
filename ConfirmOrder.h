#ifndef CONFIRMORDER_H
#define CONFIRMORDER_H

// ConcreteCommand (Command)

#include "Command.h"
#include "Waiter.h"

class ConfirmOrder : public Command {
    public:
        ConfirmOrder(Waiter* waiter);
        void execute(RestaurantTable* rt, MenuItem* m = nullptr);
    private:
        Waiter* waiter;
};

#endif // CONFIRMORDER_H
