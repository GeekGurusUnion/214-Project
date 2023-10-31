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
    private:
        State* currentState;
        Waiter* waiter;
        Observer* observer;
        int tableId;
    public:
        Table();
        void takeOrder();
        void setOrder(Order* o);
        Order* getOrder();
        void setObserver(Observer* o);
        void notifyObserver();
        virtual void detachObserver(Observer* o);
        // moet die virtual wees?
        virtual void reserve();
        virtual void occupy();
        virtual void empty();
        virtual void confirmOrder();
        virtual void cleanTable();
        virtual void addToOrder(MenuItem* item);
    private:
        Order* order;
        Observer* observer;
};
#endif // TABLE_H