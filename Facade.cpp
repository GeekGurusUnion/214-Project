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

    waiterIterator = new WaiterIterator(waiters);
    tableIterator = new TableIterator(tables);
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

Table* Facade::getTable(int index) {
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


void Facade::getSeated() {
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
    Waiter* waiter = (Waiter*) waiterIterator->first();
    while (waiterIterator->hasNext() && !waiterIterator->isAvailable(waiter)) {
        waiter = (Waiter*) waiterIterator->next();
    }
    if (waiter != nullptr) {
        waiter->addOrder(table);
        table->setWaiter(waiter);
    }
}

void Facade::addToOrder(int tableNumber, MenuItem* item) {
    RestaurantTable* table = (RestaurantTable*) tables[tableNumber];
    table->addToOrder(item);
}

void Facade::confirmOrder(int tableNumber) {
    RestaurantTable* table = (RestaurantTable*) tables[tableNumber];
    table->confirmOrder();
}

