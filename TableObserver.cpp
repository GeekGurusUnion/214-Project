#include "TableObserver.h"
#include "Waiter.h"
#include "Facade.h"

void TableObserver::update(RestaurantTable* table, std::string item, std::string customization, bool isItem, Facade* facade, int count) {
    if (table == nullptr) {
        // std::cout << "Table is null." << std::endl;
    }
    std::string observerState = table->getState()->getStateName();
    if (observerState == "Empty") {
        // std::cout << "This table is empty." << std::endl;
        if (item == "merge") {
            std::cout << "Merge table" << std::endl;
            table->getWaiter()->mergeTables(facade, count);
        }
    }
    
    if (observerState == "Serving") {
        int tNum = table->getTableNumber();
        std::cout << "Table " << tNum << " is being served food." << std::endl;
        if (item == "complaint") {
            std::cout << "Filing complaint." << std::endl;
            table->getWaiter()->complaint(table, customization);
        }
        else if (item == "bill") {
            std::cout << "Generating bill." << std::endl;
            table->getWaiter()->generateBill(table);
        }
        else if (item == "welcome") {
            std::cout << "Welcoming waiter." << std::endl;
        }
        else if (item == "tip") {
            std::cout << "Tipping bill." << std::endl;
            table->getWaiter()->tipOrder(table, count);
        }
        else if (item == "split") {
            std::cout << "Splitting bill." << std::endl;
            table->getWaiter()->splitBill(table, count);
        }
        else if (item == "pay") {
            std::cout << "Paying bill." << std::endl;
            std::cout << "Payment of $" << table->getTableCost() << " has been made." << std::endl;
            table->setState(new StateEmpty(table));
        }
    }
    else if (observerState == "Occupied") {
        // std::cout << "This table is occupied." << std::endl;
        if (isItem) {
            if (customization != "") {
                std::cout << "Adding customization to item." << std::endl;
                table->getWaiter()->addCustomization(table, item, customization);
            } else {
                std::cout << "Adding item to order." << std::endl;
                table->getWaiter()->addItem(table, item);
            }                                                    
        }
        else if (item == "confirm") {
            std::cout << "Confirming order for table " << table->getTableNumber() << std::endl;
            table->getWaiter()->confirmOrder(table);
        }
    }
}