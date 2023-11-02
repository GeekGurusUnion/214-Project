#include "Facade.h"

#define error "\x1B[31m"
#define success "\x1B[32m"
#define warning "\x1B[33m"
#define resetPrint "\x1B[0m"

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
}

Facade::~Facade() {
    for (RestaurantTable* table : tables) {
        delete table;
    }

    tables.clear();

    for (Waiter* waiter : waiters) {
        delete waiter;
    }
    waiters.clear();

    delete waiterIterator;
    delete tableIterator;

    delete mediator;
    delete floorColleague;
    delete kitchenColleague;
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

void Facade::leaveTable(int tableNumber) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    table->empty();
    std::cout << success << "Table " << table->getTableNumber() << " is now empty." << resetPrint << std::endl;
}

void Facade::getSeated() {
    // delete this->tableIterator;
    // tableIterator = createTableIterator();
    tableIterator->reset();
    RestaurantTable* table = (RestaurantTable*) tableIterator->first();
    while (tableIterator->hasNext() && !tableIterator->isAvailable(table)) {
        // std::cout << tableIterator->isAvailable(table) << resetPrint << std::endl;
        // std::cout << "searching for a table" << resetPrint << std::endl;
        table = (RestaurantTable*) tableIterator->next();
    }
    // std::cout << "Found a table" << resetPrint << std::endl;
    if (table != nullptr && table->isAvailable()) {
        table->occupy();
        getWaiter(table);
        std::cout << success << "Table " << table->getTableNumber() << " is now served by waiter " << table->getWaiter()->getName() << resetPrint << std::endl;
    } 
    else {
        std::cout << error << "Sorry, there are no available tables at the moment." << resetPrint << std::endl;
    }
}

void Facade::getWaiter(RestaurantTable* table) {
    // delete this->waiterIterator;
    // waiterIterator = createWaiterIterator();
    waiterIterator->reset();
    Waiter* waiter = (Waiter*) waiterIterator->first();
    // std::cout << waiter->getName() << resetPrint << std::endl;
    Waiter* tempWaiter = waiter;
    while (waiterIterator->hasNext()) {
        if (waiter != nullptr && waiter->getBusyOrders() < tempWaiter->getBusyOrders() && waiterIterator->isAvailable(waiter)) {
            tempWaiter = waiter;
        }
        waiter = (Waiter*) waiterIterator->next();
    }
    // std::cout << tempWaiter->getName() << resetPrint << std::endl;
    if (tempWaiter != nullptr && tempWaiter->isAvailable()) {
        tempWaiter->addOrder(table);
        table->setWaiter(tempWaiter);
    } else {
        std::cout << error << "Sorry, there are no available waiters at the moment." << resetPrint << std::endl;
    }
}

void Facade::addToOrder(int tableNumber, std::string itemName) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                          //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    table->addToOrder(itemName);
}

void Facade::confirmOrder(int tableNumber) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                           //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    table->confirmOrder();
}