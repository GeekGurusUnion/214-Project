#ifndef FACADE_H
#define FACADE_H

// Facade (Facade)
// ConcreteAggregate (Iterator)
// Client (Main)

#include "RestaurantTable.h"
#include "Waiter.h"
#include "TableIterator.h"
#include "WaiterIterator.h"
#include "StateOccupied.h"
#include <vector>

class Facade {
    private:
        Iterator* waiterIterator = new WaiterIterator(waiters);
        Iterator* tableIterator = new TableIterator(tables);
        std::vector<Table*> tables;
        std::vector<Waiter*> waiters;

        const int waiterSize = 4;
        const int tablesPerWaiter = 3;
        const int totalTables = 12;

    public:
        Facade();
        Iterator* getWaiterIterator();
        Iterator* getTableIterator();
        Table* getTable(int index);
        void getSeated();
        void getWaiter(RestaurantTable* table);
        void addToOrder(int tableNumber, MenuItem* item);
        void confirmOrder();

        int getWaiterSize() const { return waiterSize; }
        int getTablesPerWaiter() const { return tablesPerWaiter; }
        int getTotalTables() const { return totalTables; }

        TableIterator* createIterator();
};

#endif // FACADE_H
