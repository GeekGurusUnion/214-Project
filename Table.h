// pointer to order om te sien watse table het watse order
// state (occupied/empty/reserved)
// observer/waiter
// 

#ifndef TABLE_H
#define TABLE_H

// Subject (Observer) [interface]
// Aggregate (Iterator) [interface]

#include "Order.h"
class Observer;

class Table {
    public:
        Table();
        void takeOrder();
        void setOrder(Order* o);
        Order* getOrder();
        void setObserver(Observer* o);
        void notifyObserver();
        virtual void detachObserver(Observer* o) = 0;
        // moet die virtual wees?
        virtual void reserve();
        virtual void occupy();
        virtual void empty();
        virtual void confirmOrder();
        virtual void cleanTable();
        virtual void placeOrder();
    private:
        Order* order;
        Observer* observer;
};
#endif // TABLE_H