#ifndef FACADE_H
#define FACADE_H
// Facade (Facade) 
// ConcreteAggregate (Iterator) 
// Client (Main)
/**
 * @file Facade.h
 * @brief Declaration of the Facade class, which acts as a facade for the restaurant management system.
 */

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

/**
 * @class Facade
 * @brief A facade for the restaurant management system, providing a simplified interface for clients.
 *
 * Facade simplifies the complex interactions within the restaurant management system by offering a
 * high-level interface for clients. It manages restaurant tables, waiters, and the communication
 * between different colleagues.
 */
class Facade {
private:
    std::vector<RestaurantTable*> tables = std::vector<RestaurantTable*>();
    std::vector<Waiter*> waiters = std::vector<Waiter*>();
    WaiterIterator* waiterIterator;
    TableIterator* tableIterator;

    Mediator* mediator = new ConcreteMediator();

    FloorColleague* floorColleague = new FloorColleague(mediator);
    KitchenColleague* kitchenColleague = new KitchenColleague(mediator);

    int waiterSize = 4;
    int tablesPerWaiter = 3;
    int totalTables = 12;

    TableObserver* observer;

    std::string waiterNames[4] = {"John", "Jane", "Jack", "Jill"};

public:
    /**
     * @brief Constructor for the Facade class.
     */
    Facade();

    /**
     * @brief Destructor for the Facade class.
     */
    ~Facade();

    void getSeated(int customerCount);
    void addToOrder(int tableNumber, std::string itemName);
    void confirmOrder(int tableNumber);
    void generateBill(int tableNumber);
    void addCustomization(int tableNumber, std::string itemName, std::string customization);

    void getWaiter(RestaurantTable* table); // called by getSeated(); - should be called internally only

    // getters and setters if the client wants to access it (part of the facade pattern)

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

    // * testing
    std::string* getWaiterNames();
};

#endif // FACADE_H
