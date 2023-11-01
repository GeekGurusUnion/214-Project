#include "TableObserver.h"
#include "Waiter.h"

TableObserver::TableObserver(RestaurantTable* t) {
    table = t;
    observerState = table->getState();
    this->cO = new ConfirmOrder(t->getWaiter());
    this->cT = new CleanTable(t->getWaiter());
    this->tO = new TakeOrder(t->getWaiter());
}

void TableObserver::update(std::string item, bool isItem) {
    observerState = table->getState();
    if (observerState->getStateName() == "Empty") {
        std::cout << "Table is empty." << std::endl;
    }
    else if (observerState->getStateName() == "Serving") {
        std::cout << "Serving food." << std::endl;
    }
    else if (observerState->getStateName() == "Occupied") {
        std::cout << "Table is occupied." << std::endl;
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