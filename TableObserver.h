#ifndef TABLEOBSERVER_H
#define TABLEOBSERVER_H

// ConcreteObserver (Observer)

#include "Observer.h"
#include "RestaurantTable.h"
#include "State.h"

class TableObserver: public Observer {
    private:
        RestaurantTable* table;
        // observer state
        // get observer state through table.
        State* observerState;
    public:
        TableObserver(RestaurantTable* t);
        void update();
};
#endif // TABLEOBSERVER_H