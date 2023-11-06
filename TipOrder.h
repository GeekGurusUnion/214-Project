#ifndef TIP_ORDER_H
#define TIP_ORDER_H

#include "Command.h"

class TipOrder : public Command {
    public:
        TipOrder(Waiter* w);
        void execute(RestaurantTable* rt, double tip);
};

#endif // TIP_ORDER_H