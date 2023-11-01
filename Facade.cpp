#include "Facade.h"

#define error "\x1B[31m"
#define success "\x1B[32m"
#define warning "\x1B[33m"
#define reset "\x1B[0m"

Facade::Facade() {
    // Create waiters
    for (int i = 0; i < waiterSize; i++) {
        waiters.push_back(new Waiter(waiterNames[i], tablesPerWaiter, floorColleague));
    }

    // Create tables
    for (int i = 0; i < totalTables; i++) {
        tables.push_back(new RestaurantTable(i+1));
    }

    waiterIterator = createWaiterIterator();
    tableIterator = createTableIterator();

    menu.push_back(new MenuItem("Chicken", 10.99));
    menu.push_back(new MenuItem("Beef", 12.99));
    menu.push_back(new MenuItem("Pork", 11.99));
    menu.push_back(new MenuItem("Fish", 13.99));
    menu.push_back(new MenuItem("Lamb", 14.99));
    menu.push_back(new MenuItem("Pasta", 15.99));
    menu.push_back(new MenuItem("Pizza", 16.99));
    menu.push_back(new MenuItem("Salad", 17.99));
    menu.push_back(new MenuItem("Soup", 18.99));
    menu.push_back(new MenuItem("Steak", 19.99));
}

void Facade::addTable(RestaurantTable* table) {
    tables.push_back(table);
}

void Facade::addWaiter(Waiter* waiter) {
    waiters.push_back(waiter);
}

Iterator* Facade::getWaiterIterator() {
    return waiterIterator;
}

Iterator* Facade::getTableIterator() {
    return tableIterator;
}

RestaurantTable* Facade::getTable(int index) {
    if (index-1 < 0 || index-1 >= tables.size()) {
        return nullptr;
    }
    return tables[index-1];
}

int Facade::getWaiterSize() const { 
    return waiterSize;
}

int Facade::getTablesPerWaiter() const {
    return tablesPerWaiter;
}

int Facade::getTotalTables() const {
    return totalTables;
}

TableIterator *Facade::createTableIterator() {
    return new TableIterator(tables);
}

WaiterIterator* Facade::createWaiterIterator() {
    return new WaiterIterator(waiters);
}

MenuItem *Facade::getMenuItem(std::string name)
{
    for (int i = 0; i < menu.size(); i++) {
        if (menu[i]->getName() == name) {
            return menu[i];
        }
    }
    return nullptr;
}

void Facade::getSeated() {
    tableIterator = createTableIterator();
    RestaurantTable* table = (RestaurantTable*) tableIterator->first();
    while (tableIterator->hasNext() && !tableIterator->isAvailable(table)) {
        // std::cout << tableIterator->isAvailable(table) << reset << std::endl;
        // std::cout << "searching for a table" << reset << std::endl;
        table = (RestaurantTable*) tableIterator->next();
    }
    // std::cout << "Found a table" << reset << std::endl;
    if (table != nullptr && table->isAvailable()) {
        table->occupy();
        getWaiter(table);
        std::cout << success << "Table " << table->getTableNumber() << " is now served by waiter " << table->getWaiter()->getName() << reset << std::endl;
    } 
    else {
        std::cout << error << "Sorry, there are no available tables at the moment." << reset << std::endl;
    }
}

void Facade::getWaiter(RestaurantTable* table) {
    waiterIterator = createWaiterIterator();
    Waiter* waiter = (Waiter*) waiterIterator->first();
    // std::cout << waiter->getName() << reset << std::endl;
    Waiter* tempWaiter = waiter;
    while (waiterIterator->hasNext()) {
        if (waiter != nullptr && waiter->getBusyOrders() < tempWaiter->getBusyOrders() && waiterIterator->isAvailable(waiter)) {
            tempWaiter = waiter;
        }
        waiter = (Waiter*) waiterIterator->next();
    }
    // std::cout << tempWaiter->getName() << reset << std::endl;
    if (tempWaiter != nullptr && tempWaiter->isAvailable()) {
        tempWaiter->addOrder(table);
        table->setWaiter(tempWaiter);
    } else {
        std::cout << error << "Sorry, there are no available waiters at the moment." << reset << std::endl;
    }
}

void Facade::addToOrder(int tableNumber, std::string itemName) {
    MenuItem* item = getMenuItem(itemName);
    if (item == nullptr) {
        std::cout << error << "Sorry, we don't have that item on the menu!" << reset << std::endl;
        return;
    }
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {
        std::cout << error << "Sorry, that table is not occupied!" << reset << std::endl;
        return;
    }
    table->addToOrder(item);
    std::cout << success << itemName << " added to your order!" << reset << std::endl;
}

void Facade::confirmOrder(int tableNumber) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {
        std::cout << error << "Sorry, that table is not occupied!" << reset << std::endl;
        return;
    }
    table->confirmOrder();
}



