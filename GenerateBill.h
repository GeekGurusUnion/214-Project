#ifndef GENERATE_BILL_H
#define GENERATE_BILL_H

// ConcreteCommand (Command)

#include "Command.h"
class Waiter;

class GenerateBill : public Command {
    public:
        GenerateBill(Waiter* waiter);
        void execute(RestaurantTable* rt, MenuItem* m);
};

#endif // GENERATE_BILL_H
