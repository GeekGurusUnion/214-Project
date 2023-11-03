#ifndef CONFIRMORDER_H
#define CONFIRMORDER_H

// ConcreteCommand (Command)

#include "Command.h"
class Waiter;
class RestaurantTable;
class MenuItem;
class FloorColleague;

class ConfirmOrder : public Command {
    private:
        FloorColleague* floorColleague;
    public:
        ConfirmOrder(Waiter* waiter, FloorColleague* floorColleague);
        void execute(RestaurantTable* rt, MenuItem* m);
};

#endif // CONFIRMORDER_H
