#ifndef COLLEAGUE_H
#define COLLEAGUE_H

// Colleague (Mediator) [interface]

class Mediator;
class Order;

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