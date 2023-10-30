// pointer to order om te sien watse table het watse order
// state (occupied/empty/reserved)
// observer/waiter
// 

#ifndef TABLE_H
#define TABLE_H

// Subject (Observer) [interface]
// Aggregate (Iterator) [interface]

#include "Order.h"
#include "State.h"
#include "Observer.h"

class Table {
    public:
        Table();
        void takeOrder();
        void setOrder(Order* o);
        void setState(State* s);
        State* getState();
        Order* getOrder();
        void setObserver(Observer* o);
        void notifyObserver();
        virtual void detachObserver(Observer* o) = 0;
        // moet die virtual wees?
    private:
        State* state;
        Order* order;
        Observer* observer;
};
#endif // TABLE_H