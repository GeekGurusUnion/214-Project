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
/**
 * @brief The Facade class provides a simplified interface to the complex subsystems of the restaurant.
 * 
 * The Facade class is responsible for managing the interactions between the Waiter, RestaurantTable, and MenuItem classes.
 * It provides a simplified interface to the complex subsystems of the restaurant, allowing clients to interact with the restaurant
 * without needing to understand the underlying complexity of the system.
 */
class Facade {
private:
    std::vector<RestaurantTable*> tables = std::vector<RestaurantTable*>();
    std::vector<Waiter*> waiters = std::vector<Waiter*>();
    Iterator* waiterIterator;
    Iterator* tableIterator;

    Mediator* mediator = new ConcreteMediator();

    Colleague* floorColleague = new FloorColleague(mediator);
    Colleague* kitchenColleague = new KitchenColleague(mediator);

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

    /**
     * @brief Assigns a table to a group of customers.
     * 
     * @param customerCount The number of customers in the group.
     */
    void getSeated(int customerCount);

    /**
     * @brief Adds an item to a table's order.
     * 
     * @param tableNumber The number of the table.
     * @param itemName The name of the item to add to the order.
     */
    void addToOrder(int tableNumber, std::string itemName);

    /**
     * @brief Confirms the order for a table.
     * 
     * @param tableNumber The number of the table.
     */
    void confirmOrder(int tableNumber);

    /**
     * @brief Generates a bill for a table.
     * 
     * @param tableNumber The number of the table.
     */
    void generateBill(int tableNumber);

    /**
     * @brief Adds a customization to an item on a table's order.
     * 
     * @param tableNumber The number of the table.
     * @param itemName The name of the item to customize.
     * @param customization The customization to add to the item.
     */
    void addCustomization(int tableNumber, std::string itemName, std::string customization);

    /**
     * @brief Merges two tables together.
     * 
     * @param rt The table to merge with.
     * @param count The number of tables to merge.
     */
    void mergeTables(RestaurantTable* rt, int count);

    /**
     * @brief Adds a tip to a table's bill.
     * 
     * @param tableNumber The number of the table.
     * @param tip The amount of the tip.
     */
    void tip(int tableNumber, double tip);

    /**
     * @brief Splits a table's bill into multiple bills.
     * 
     * @param tableNumber The number of the table.
     * @param count The number of bills to split the table's bill into.
     */
    void splitBill(int tableNumber, int count);

    /**
     * @brief Registers a complaint from a table.
     * 
     * @param tableNumber The number of the table.
     * @param complaint The complaint to register.
     */
    void complain(int tableNumber, std::string complaint);

    /**
     * @brief Pays the bill for a table.
     * 
     * @param tableNumber The number of the table.
     */
    void payBill(int tableNumber);

    /**
     * @brief Assigns a waiter to a table.
     * 
     * This function is called internally by getSeated() and should not be called directly by clients.
     * 
     * @param table The table to assign a waiter to.
     */
    void getWaiter(RestaurantTable* table);

    /**
     * @brief Adds a table to the restaurant.
     * 
     * @param table The table to add.
     */
    void addTable(RestaurantTable* table);

    /**
     * @brief Adds a waiter to the restaurant.
     * 
     * @param waiter The waiter to add.
     */
    void addWaiter(Waiter* waiter);

    /**
     * @brief Removes a table from the restaurant.
     * 
     * @param table The table to remove.
     */
    void removeTable(RestaurantTable* table);

    /**
     * @brief Nullifies a table in the restaurant.
     * 
     * @param table The table to nullify.
     */
    void nullifyTable(RestaurantTable* table);

    /**
     * @brief Returns an iterator for the waiters in the restaurant.
     * 
     * @return Iterator* An iterator for the waiters in the restaurant.
     */
    Iterator* getWaiterIterator();

    /**
     * @brief Returns an iterator for the tables in the restaurant.
     * 
     * @return Iterator* An iterator for the tables in the restaurant.
     */
    Iterator* getTableIterator();

    /**
     * @brief Returns a table by index.
     * 
     * @param index The index of the table to return.
     * @return RestaurantTable* The table at the specified index.
     */
    RestaurantTable* getTable(int index);

    /**
     * @brief Returns the number of waiters in the restaurant.
     * 
     * @return int The number of waiters in the restaurant.
     */
    int getWaiterSize() const;

    /**
     * @brief Returns the number of tables each waiter is responsible for.
     * 
     * @return int The number of tables each waiter is responsible for.
     */
    int getTablesPerWaiter() const;

    /**
     * @brief Returns the total number of tables in the restaurant.
     * 
     * @return int The total number of tables in the restaurant.
     */
    int getTotalTables() const;

    /**
     * @brief Creates a new TableIterator.
     * 
     * @return TableIterator* A new TableIterator.
     */
    TableIterator* createTableIterator();

    /**
     * @brief Creates a new WaiterIterator.
     * 
     * @return WaiterIterator* A new WaiterIterator.
     */
    WaiterIterator* createWaiterIterator();

    /**
     * @brief Returns a MenuItem by name.
     * 
     * @param name The name of the MenuItem to return.
     * @return MenuItem* The MenuItem with the specified name.
     */
    MenuItem* getMenuItem(std::string name);

    /**
     * @brief Removes a table from a waiter's list of tables.
     * 
     * @param tableNumber The number of the table to remove.
     */
    void leaveTable(int tableNumber);

    // * testing
    /**
     * @brief Returns an array of waiter names.
     * 
     * @return std::string* An array of waiter names.
     */
    std::string* getWaiterNames();
};

#endif // FACADE_H
