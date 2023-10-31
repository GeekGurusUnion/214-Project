#ifndef CONFIRMORDER_H
#define CONFIRMORDER_H

// ConcreteCommand (Command)

#include "Command.h"
class Waiter;
class RestaurantTable;
class MenuItem;

class ConfirmOrder : public Command {
    private:
        Waiter* waiter;
    public:
        ConfirmOrder(Waiter* waiter);
        void execute(RestaurantTable* rt, MenuItem* m);
};

#endif // CONFIRMORDER_H
