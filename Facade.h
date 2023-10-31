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
#include "ConcreteMediator.h"
#include <vector>

class Facade {
    private:
        Iterator* waiterIterator = new WaiterIterator(waiters);
        Iterator* tableIterator = new TableIterator(tables);
        std::vector<Table*> tables = std::vector<Table*>();
        std::vector<Waiter*> waiters = std::vector<Waiter*>();

        Mediator* mediator = new ConcreteMediator();

        FloorColleague* floorColleague = new FloorColleague(mediator);
        KitchenColleague* kitchenColleague = new KitchenColleague(mediator);

        const int waiterSize = 4;
        const int tablesPerWaiter = 3;
        const int totalTables = 12;

    public:
        Facade();

        void getSeated();
        void addToOrder(int tableNumber, MenuItem* item);
        void confirmOrder(int tableNumber);

        void getWaiter(RestaurantTable* table); // called by getSeated(); - should be called internally only

        // getters and setters if client wants to access it (part of the facade pattern)

        void addTable(Table* table);
        void addWaiter(Waiter* waiter);

        Iterator* getWaiterIterator();
        Iterator* getTableIterator();
        Table* getTable(int index);
        int getWaiterSize() const;
        int getTablesPerWaiter() const;
        int getTotalTables() const;

        TableIterator* createIterator();
};

#endif // FACADE_H
