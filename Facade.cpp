#include "Facade.h"

Facade::Facade() {
    // Create waiters
    for (int i = 0; i < waiterSize; i++) {
        waiters.push_back(new Waiter(waiterNames[i], tablesPerWaiter, floorColleague));
    }

    // Create tables
    for (int i = 0; i < totalTables; i++) {
        tables.push_back(new RestaurantTable(i));
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
    if (index < 0 || index >= tables.size()) {
        return nullptr;
    }
    return tables[index];
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
        // std::cout << tableIterator->isAvailable(table) << std::endl;
        // std::cout << "searching for a table" << std::endl;
        table = (RestaurantTable*) tableIterator->next();
    }
    // std::cout << "Found a table" << std::endl;
    if (table != nullptr) {
        table->occupy();
        getWaiter(table);
    }
    std::cout << "Table " << table->getTableNumber() << " is now served by waiter " << table->getWaiter()->getName() << std::endl;
}

void Facade::getWaiter(RestaurantTable* table) {
    waiterIterator = createWaiterIterator();
    Waiter* waiter = (Waiter*) waiterIterator->first();
    // std::cout << waiter->getName() << std::endl;
    Waiter* tempWaiter = waiter;
    while (waiterIterator->hasNext()) {
        // std::cout << "Waiter " + waiter->getName() << std::endl;
        waiter = (Waiter*) waiterIterator->next();
        if (waiter != nullptr && waiter->getBusyOrders() < tempWaiter->getBusyOrders() && waiterIterator->isAvailable(waiter)) {
            tempWaiter = waiter;
        }
    }
    // std::cout << tempWaiter->getName() << std::endl;
    if (tempWaiter != nullptr) {
        tempWaiter->addOrder(table);
        table->setWaiter(tempWaiter);
    } else {
        std::cout << "Sorry, there are no available waiters at the moment." << std::endl;
    }
}

void Facade::addToOrder(int tableNumber, std::string itemName) {
    MenuItem* item = getMenuItem(itemName);
    if (item == nullptr) {
        std::cout << "Sorry, we don't have that item on the menu!" << std::endl;
        return;
    }
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {
        std::cout << "Sorry, that table is not occupied!" << std::endl;
        return;
    }
    table->addToOrder(item);
    std::cout << itemName << " added to your order!" << std::endl;
}

void Facade::confirmOrder(int tableNumber) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {
        std::cout << "Sorry, that table is not occupied!" << std::endl;
        return;
    }
    table->confirmOrder();
}



