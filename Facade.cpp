#include "Facade.h"

Facade::Facade() {
    // Create waiters
    for (int i = 0; i < waiterSize; i++) {
        waiters.push_back(new Waiter(tablesPerWaiter, floorColleague));
    }

    // Create tables
    for (int i = 0; i < totalTables; i++) {
        tables.push_back(new RestaurantTable(i));
    }
}

void Facade::addTable(Table* table) {
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
    RestaurantTable* table = nullptr;
    while (tableIterator->hasNext() && !tableIterator->isAvailable()) {
        table = (RestaurantTable*) tableIterator->next();
    }
    if (table != nullptr) {
        table->occupy();
        getWaiter(table);
    }
}

void Facade::getWaiter(RestaurantTable* table) {
    Waiter* waiter = nullptr;
    while (waiterIterator->hasNext() && !waiterIterator->isAvailable()) {
        waiter = (Waiter*) waiterIterator->next();
    }
    if (waiter != nullptr) {
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

