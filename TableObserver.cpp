#include "TableObserver.h"
#include "Waiter.h"

TableObserver::TableObserver(RestaurantTable* t) : table(t) {
}

TableObserver::~TableObserver() {
    std::cout << "Destructor Table: " << table->getTableNumber() << std::endl;
    delete cO;
    delete cT;
    delete tO;
    // delete table;
}

void TableObserver::update(std::string item, bool isItem) {
    std::string observerState = table->getState()->getStateName();
    if (observerState == "Empty") {
        std::cout << "This table is empty." << std::endl;
    }
    if (table->getWaiter() != nullptr) {
        cO = new ConfirmOrder(table->getWaiter());
        cT = new CleanTable(table->getWaiter());
        tO = new TakeOrder(table->getWaiter());
    } else {
        std::cout << "TableObserver: No waiter found for table " << table << ".\n";
        return;
    }
    
    if (observerState == "Serving") {
        std::cout << "This table is being served food." << std::endl;
    }
    else if (observerState == "Occupied") {
        std::cout << "This table is occupied." << std::endl;
        MenuItem* menuItem = table->getWaiter()->getMenuItem(item);
        if (isItem) {                                                             
            std::cout << "Adding item to order." << std::endl;
            tO->execute(table, menuItem);
        }
        else if (item == "confirm") {
            std::cout << "Confirming order." << std::endl;
            cO->execute(table, nullptr);
        }
        else if (item == "clean") {
            std::cout << "Cleaning table." << std::endl;
            cT->execute(table, nullptr);
        }
        else if (item == "welcome") {
            std::cout << "Welcoming waiter." << std::endl;
        }
    }
}