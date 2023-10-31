#ifndef CLEANTABLE_H
#define CLEANTABLE_H

// ConcreteCommand (Command)

#include "Command.h"
class Waiter;

class CleanTable : public Command {
    private:
        Waiter* waiter;
    public:
        CleanTable(Waiter* waiter);
        void execute(RestaurantTable* rt, MenuItem* m);
};

#endif // CLEANTABLE_H
