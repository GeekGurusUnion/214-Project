// pointer to order om te sien watse table het watse order
// state (occupied/empty/reserved)
// observer/waiter
// 

#ifndef TABLE_H
#define TABLE_H
#include "Order.h"
#include "State.h"
class Table{
    public:
        Table();
        void takeOrder();
        void setOrder(Order* o);
        void setState(State* s);
        State* getState();
        Order* getOrder();
        void setObserver(Observer* o);
        void notifyObserver();
        void detachObserver(Observer* o);
        // moet die virtual wees?
    private:
        State* state;
        Order* order;
        Observer* observer;
};
#endif // !TABLE_H