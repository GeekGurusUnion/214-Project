#ifndef TAKEORDER_H
#define TAKEORDER_H

// ConcreteCommand (Command)

#include "Command.h"
#include "Waiter.h"

class TakeOrder : public Command {
    private:
        Waiter* waiter;
    public:
        TakeOrder(Waiter* waiter);
        void execute(RestaurantTable* rt, MenuItem* m);
};

#endif // TAKEORDER_H
