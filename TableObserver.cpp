#include "TableObserver.h"
#include "Waiter.h"

void TableObserver::update(RestaurantTable* table, std::string item, bool isItem) {
    std::string observerState = table->getState()->getStateName();
    if (observerState == "Empty") {
        std::cout << "This table is empty." << std::endl;
    }
    
    if (observerState == "Serving") {
        std::cout << "This table is being served food." << std::endl;
    }
    else if (observerState == "Occupied") {
        std::cout << "This table is occupied." << std::endl;
        if (isItem) {                                                             
            std::cout << "Adding item to order." << std::endl;
            table->getWaiter()->addItem(table, item);
        }
        else if (item == "confirm") {
            std::cout << "Confirming order." << std::endl;
            table->getWaiter()->confirmOrder(table);
        }
        else if (item == "welcome") {
            std::cout << "Welcoming waiter." << std::endl;
        }
    }
}