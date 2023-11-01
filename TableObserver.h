#ifndef TABLEOBSERVER_H
#define TABLEOBSERVER_H

// ConcreteObserver (Observer)

#include "RestaurantTable.h"
#include "State.h"

class TableObserver {
    private:
        RestaurantTable* table;
        // observer state
        // get observer state through table.
        State* observerState;
        Command* cO;
        Command* cT;
        Command* tO;
    public:
        TableObserver(RestaurantTable* t);
        void update(std::string item, bool isItem);
};
#endif // TABLEOBSERVER_H