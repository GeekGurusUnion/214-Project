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
        if (i < 4)
            tables.push_back(new RestaurantTable(i+1, 2));
        if (i >= 4 && i < 8)
            tables.push_back(new RestaurantTable(i+1, 4));
        if (i >= 8 && i < 12)
            tables.push_back(new RestaurantTable(i+1, 6));
    }

    waiterIterator = createWaiterIterator();
    tableIterator = createTableIterator();

    observer = new TableObserver();
}

Facade::~Facade() {
    while (!tables.empty()) {
        RestaurantTable* table = tables.back();
        delete table;
        tables.pop_back();
    }

    tables.clear();

    while (!waiters.empty()) {
        Waiter* waiter = waiters.back();
        delete waiter;
        waiters.pop_back();
    }

    waiters.clear();

    delete waiterIterator;
    delete tableIterator;

    delete observer;

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

void Facade::removeTable(RestaurantTable *table) {
    for (int i = 0; i < tables.size(); i++) {
        if (tables[i] == table) {
            tables.erase(tables.begin() + i);
            return;
        }
    }
}

void Facade::nullifyTable(RestaurantTable *table) {
    for (int i = 0; i < tables.size(); i++) {
        if (tables[i] == table) {
            tables[i]->setTableSize(0);
            return;
        }
    }
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
    observer->update(table, "leave", "", false, this, 0);
}

int Facade::getSeated(int customerCount) {
    // std::cout << warning << "A group of " << customerCount << " customers have arrived." << resetPrint << std::endl;
    tableIterator->reset();
    RestaurantTable* table = (RestaurantTable*) tableIterator->first();
    while (tableIterator->hasNext()) {
        if ((table->getTableSize() >= customerCount) && table->isAvailable())
            break;
        table = (RestaurantTable*) tableIterator->next();
    }

    if (table != nullptr && table->isAvailable() && table->getTableSize() >= customerCount) {
        table->occupy();
        getWaiter(table);
        std::cout << success << "Table " << table->getTableNumber() << " with seating size " << table->getTableSize() << " is now served by waiter " << table->getWaiter()->getName() << resetPrint << std::endl;
        return table->getTableNumber();
    }
    else {
        tableIterator->reset();
        RestaurantTable* table = (RestaurantTable*) tableIterator->first();
        getWaiter(table);
        mergeTables(table, customerCount);
        return getTableNumber(customerCount);
    }
}

int Facade::getTableNumber(int customerCount) {
    for (int i = 0; i < totalTables; i++) {
        if (tables[i]->getTableSize() >= customerCount && !tables[i]->isAvailable()) {
            return tables[i]->getTableNumber();
        }
    }
    return -1;
}

void Facade::getWaiter(RestaurantTable* table) {
    waiterIterator->reset();
    Waiter* waiter = (Waiter*) waiterIterator->first();
    Waiter* tempWaiter = waiter;
    while (waiterIterator->hasNext()) {
        if (waiter != nullptr && waiter->getBusyOrders() < tempWaiter->getBusyOrders()) {
            if (waiter->isAvailable()) {
                tempWaiter = waiter;
            }
        }
        waiter = (Waiter*) waiterIterator->next();
    }

    if (tempWaiter != nullptr && tempWaiter->isAvailable()) {
        tempWaiter->addOrder(table);
        table->setWaiter(tempWaiter);
    } else {
        std::cout << error << "Sorry, there are no available waiters at the moment." << resetPrint << std::endl;
    }
}

void Facade::generateBill(int tableNumber) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                          //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    observer->update(table, "bill", "", false, this, 0);
}

void Facade::addCustomization(int tableNumber, std::string itemName, std::string customization) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                          //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    observer->update(table, itemName, customization, true, this, 0);
}

void Facade::mergeTables(RestaurantTable* rt, int count) {
    observer->update(rt, "merge", "", false, this, count);
}

void Facade::tip(int tableNumber, double tip) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                          //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    observer->update(table, "tip", "", false, this, tip);
}

void Facade::splitBill(int tableNumber, int count) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                          //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    observer->update(table, "split", "", false, this, count);
}

void Facade::complain(int tableNumber, std::string complaint) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                          //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    observer->update(table, "complaint", complaint, false, this, 0);
}

void Facade::payBill(int tableNumber) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                          //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    observer->update(table, "pay", "", false, this, 0);
}

void Facade::addToOrder(int tableNumber, std::string itemName) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                          //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    observer->update(table, itemName, "", true, this, 0);
}

void Facade::confirmOrder(int tableNumber) {
    RestaurantTable* table = getTable(tableNumber);
    if (!table || table->isAvailable()) {                                           //isAvailable() always returns false?
        std::cout << error << "Sorry, that table is not occupied!" << resetPrint << std::endl;
        return;
    }
    observer->update(table, "confirm", "", false, this, 0);
}

// * testing
std::string* Facade::getWaiterNames() {
    return waiterNames;
}

void Facade::setTablesPerWaiter(int size) {
    tablesPerWaiter = size;
    
}

void Facade::setWaiterSize(int size) {
    waiterSize = size;
    for (int i = 0; i < waiterSize; i++) {
        waiters.push_back(new Waiter(waiterNames[i], tablesPerWaiter, floorColleague));
    }
}

void Facade::setTotalTables(int size) {
    totalTables = size;
    for (int i = 0; i < totalTables; i++) {
        if (i < 4)
            tables.push_back(new RestaurantTable(i+1, 2));
        if (i >= 4 && i < 8)
            tables.push_back(new RestaurantTable(i+1, 4));
        if (i >= 8 && i < 12)
            tables.push_back(new RestaurantTable(i+1, 6));
    }
}

void Facade::setObserver(TableObserver* observer) {
    this->observer = observer;
}

void Facade::setWaiterIterator(WaiterIterator* waiterIterator) {
    this->waiterIterator = waiterIterator;
}
