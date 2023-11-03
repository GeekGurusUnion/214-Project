#ifndef TABLE_OBSERVER_H
#define TABLE_OBSERVER_H

// ConcreteObserver (Observer)

#include "State.h"

class RestaurantTable;

class TableObserver {
    public:
        void update(RestaurantTable* t, std::string item, bool isItem);
};
#endif // TABLE_OBSERVER_H