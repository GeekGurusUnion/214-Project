#ifndef TABLEOBSERVER_H
#define TABLEOBSERVER_H

// ConcreteObserver (Observer)

#include "Observer.h"
#include "RestaurantTable.h"
#include "State.h"

class TableObserver: public Observer {
    public:
        TableObserver(RestaurantTable* t);
        void update();
    private:
        RestaurantTable* table;
        // observer state
        // get observer state through table.
        State* observerState;
};
#endif // TABLEOBSERVER_H