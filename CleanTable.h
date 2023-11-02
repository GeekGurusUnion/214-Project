#ifndef CLEANTABLE_H
#define CLEANTABLE_H

// ConcreteCommand (Command)

#include "Command.h"
class Waiter;

class CleanTable : public Command {
    public:
        CleanTable(Waiter* waiter);
        void execute(RestaurantTable* rt, MenuItem* m);
};

#endif // CLEANTABLE_H
