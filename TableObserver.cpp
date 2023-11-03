#include "TableObserver.h"
#include "Waiter.h"

void TableObserver::update(RestaurantTable* table, std::string item, bool isItem) {
    std::string observerState = table->getState()->getStateName();
    if (observerState == "Empty") {
        std::cout << "This table is empty." << std::endl;
    }
    // if (table->getWaiter() != nullptr) {
    //     cO = new ConfirmOrder(table->getWaiter());
    //     cT = new CleanTable(table->getWaiter());
    //     tO = new TakeOrder(table->getWaiter());
    // } else {
    //     std::cout << "TableObserver: No waiter found for table " << table << ".\n";
    //     return;
    // }
    
    if (observerState == "Serving") {
        std::cout << "This table is being served food." << std::endl;
    }
    else if (observerState == "Occupied") {
        std::cout << "This table is occupied." << std::endl;
        // MenuItem* menuItem = table->getWaiter()->getMenuItem(item);
        if (isItem) {                                                             
            std::cout << "Adding item to order." << std::endl;
            // tO->execute(table, menuItem);
            table->getWaiter()->addItem(table, item);
        }
        else if (item == "confirm") {
            std::cout << "Confirming order." << std::endl;
            // cO->execute(table, nullptr);
            table->getWaiter()->confirmOrder(table);
        }
        else if (item == "welcome") {
            std::cout << "Welcoming waiter." << std::endl;
        }
    }
}