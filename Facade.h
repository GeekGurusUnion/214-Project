#ifndef FACADE_H
#define FACADE_H

// Facade (Facade)
// ConcreteAggregate (Iterator)
// Client (Main)

#include "RestaurantTable.h"
#include "Waiter.h"
// #include "TableIterator.h"
// #include "WaiterIterator.h"
#include "StateOccupied.h"
#include "ConcreteMediator.h"

#include "FloorColleague.h"
#include "KitchenColleague.h"

#include <vector>

class WaiterIterator;
class TableIterator;

class Facade {
    private:
        std::vector<RestaurantTable*> tables = std::vector<RestaurantTable*>();
        std::vector<Waiter*> waiters = std::vector<Waiter*>();
        WaiterIterator* waiterIterator = new WaiterIterator(waiters);
        TableIterator* tableIterator = new TableIterator(tables);

        Mediator* mediator = new ConcreteMediator();

        FloorColleague* floorColleague = new FloorColleague(mediator);
        KitchenColleague* kitchenColleague = new KitchenColleague(mediator);

        const int waiterSize = 4;
        const int tablesPerWaiter = 3;
        const int totalTables = 12;

        std::string waiterNames[4] = {"John", "Jane", "Jack", "Jill"};

    public:
        Facade();
        ~Facade();

        void getSeated();
        void addToOrder(int tableNumber, MenuItem* item);
        void confirmOrder(int tableNumber);

        void getWaiter(RestaurantTable* table); // called by getSeated(); - should be called internally only

        // getters and setters if client wants to access it (part of the facade pattern)

        void addTable(RestaurantTable* table);
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
