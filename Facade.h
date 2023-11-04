#ifndef FACADE_H
#define FACADE_H

// Facade (Facade)
// ConcreteAggregate (Iterator)
// Client (Main)

#include "RestaurantTable.h"
#include "Waiter.h"
#include "StateOccupied.h"
#include "ConcreteMediator.h"

#include "FloorColleague.h"
#include "KitchenColleague.h"

#include "TableObserver.h"

#include <vector>

class WaiterIterator;
class TableIterator;

class Facade {
    private:
        std::vector<RestaurantTable*> tables = std::vector<RestaurantTable*>();
        std::vector<Waiter*> waiters = std::vector<Waiter*>();
        WaiterIterator* waiterIterator;
        TableIterator* tableIterator;

        Mediator* mediator = new ConcreteMediator();

        FloorColleague* floorColleague = new FloorColleague(mediator);
        KitchenColleague* kitchenColleague = new KitchenColleague(mediator);

        const int waiterSize = 4;
        const int tablesPerWaiter = 3;
        const int totalTables = 12;

        TableObserver* observer;

        std::string waiterNames[4] = {"John", "Jane", "Jack", "Jill"};

    public:
        Facade();
        ~Facade();

        void getSeated(int customerCount);
        void addToOrder(int tableNumber, std::string itemName);
        void confirmOrder(int tableNumber);

        void getWaiter(RestaurantTable* table); // called by getSeated(); - should be called internally only

        // getters and setters if client wants to access it (part of the facade pattern)

        void addTable(RestaurantTable* table);
        void addWaiter(Waiter* waiter);

        Iterator* getWaiterIterator();
        Iterator* getTableIterator();
        RestaurantTable* getTable(int index);
        int getWaiterSize() const;
        int getTablesPerWaiter() const;
        int getTotalTables() const;

        TableIterator* createTableIterator();
        WaiterIterator* createWaiterIterator();

        MenuItem* getMenuItem(std::string name);

        void leaveTable(int tableNumber);
};

#endif // FACADE_H
