#ifndef CUSTOMIZE_ORDER_H
#define CUSTOMIZE_ORDER_H

// ConcreteCommand (Command)

#include "Command.h"
class Waiter;

class CustomizeOrder : public Command {
    public:
        CustomizeOrder(Waiter* waiter);
        void execute(RestaurantTable* rt, std::string m, std::string customization);
        void execute(RestaurantTable* rt, MenuItem* m) {}
};

#endif // CUSTOMIZE_ORDER_H
