#include "TableObserver.h"

TableObserver::TableObserver(RestaurantTable* t) {
    table = t;
    observerState = table->getState();
}

void TableObserver::update() {
    observerState = table->getState();
    if (observerState->getStateName() == "Empty") {
        table->cleanTable();
    }
    else if (observerState->getStateName() == "Serving") {
        std::cout << "Serving food." << std::endl;
    }
    else if (observerState->getStateName() == "Occupied") {
        std::cout << "Occupied. Ready to order." << std::endl;
    }
}