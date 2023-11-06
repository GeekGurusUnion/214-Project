#ifndef SPLIT_BILL_H
#define SPLIT_BILL_H

#include "Command.h"

class SplitBill : public Command {
    public:
        SplitBill(Waiter* w);
        void execute(RestaurantTable* rt, double count);
};

#endif // SPLIT_BILL_H