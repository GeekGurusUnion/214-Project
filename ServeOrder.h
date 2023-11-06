#ifndef SERVE_ORDER_H
#define SERVE_ORDER_H

#include "Command.h"

class Waiter;
class RestaurantTable;

class ServeOrder : public Command {
    private:
        RestaurantTable* table;
    public:
        ServeOrder(Waiter* waiter, RestaurantTable* table);
        void execute(RestaurantTable* rt, MenuItem* menuItem);
};

#endif // SERVE_ORDER_H