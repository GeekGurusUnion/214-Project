#ifndef TABLE_OBSERVER_H
#define TABLE_OBSERVER_H

// ConcreteObserver (Observer)

#include "RestaurantTable.h"
#include "State.h"

class TableObserver {
    private:
        RestaurantTable* table;
        // observer state
        // get observer state through table.
        // State* observerState;
        
    public:
        TableObserver(RestaurantTable* t);
        ~TableObserver();
        void update(std::string item, bool isItem);
};
#endif // TABLE_OBSERVER_H