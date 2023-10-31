#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "Mediator.h"
#include "Order.h"

// Colleague (Mediator) [interface]

class Colleague {
    protected:
        Mediator* mediator;
        Order* order;
    public:
        Colleague(Mediator* mediator);
        virtual void changed();
        void setOrder(Order* order);
        Order* getOrder();
};

#endif // COLLEAGUE_H