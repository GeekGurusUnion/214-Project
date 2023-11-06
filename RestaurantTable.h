#ifndef RESTAURANT_TABLE_H_
#define RESTAURANT_TABLE_H_
// ConcreteSubject (Observer)
// Context (State)
// Invoker (Command)
// ConcreteAggregate (Iterator)

/**
 * @file RestaurantTable.h
 * @brief Definition of the RestaurantTable class.
 */

#include "StateEmpty.h"
#include "Order.h"
#include "ConfirmOrder.h"
#include "TakeOrder.h"
#include "GenerateBill.h"
#include "CustomizeOrder.h"
#include "SplitBill.h"
#include "TipOrder.h"
#include "MergeTables.h"
#include "Complaints.h"
#include "TableObserver.h"
#include "TableIterator.h"
#include <iostream> 
// Forward declarations
class Waiter;
class TableObserver;
class Order;

/**
 * @class RestaurantTable
 * @brief Represents a restaurant table with various functionalities.
 *
 * This class represents a restaurant table that can change states, have an associated waiter,
 * manage orders, and notify the waiter of various actions.
 */
class RestaurantTable {
private:
    /**
     * @var currentState
     * @brief The current state of the table.
     */
    State* currentState;

    /**
     * @var waiter
     * @brief The waiter serving the table.
     */
    Waiter* waiter = nullptr;

    /**
     * @var tableNumber
     * @brief The table number or identifier.
     */
    int tableNumber;

    /**
     * @var tableSize
     * @brief The size or capacity of the table.
     */
    int tableSize;

    /**
     * @var order
     * @brief The order associated with the table.
     */
    Order* order;

    /**
     * @var costPerPerson
    */
    float costPerPerson;

public:
    /**
     * @brief Constructor for RestaurantTable.
     * @param i The table number or identifier.
     * @param t The size or capacity of the table.
     */
    RestaurantTable(int i, int t);

    /**
     * @brief Destructor for RestaurantTable.
     */
    ~RestaurantTable();

    /**
     * @brief Set the current state of the table.
     * @param state Pointer to the new state.
     */
    void setState(State* state);

    /**
     * @brief Get the current state of the table.
     * @return Pointer to the current state.
     */
    State* getState();

    /**
     * @brief Transition the table to the "Occupied" state.
     */
    void occupy();

    /**
     * @brief Get the waiter serving the table.
     * @return Pointer to the waiter serving the table.
     */
    Waiter* getWaiter() const;

    /**
     * @brief Set the waiter serving the table.
     * @param waiter Pointer to the waiter.
     */
    void setWaiter(Waiter* waiter);

    /**
     * @brief Get the order associated with the table.
     * @return Pointer to the order.
     */
    Order* getOrder() const;

    /**
     * @brief Check if the table is available (not occupied).
     * @return True if the table is available, false otherwise.
     */
    bool isAvailable() const;

    /**
     * @brief Get the table number or identifier.
     * @return The table number.
     */
    int getTableNumber() const;

    /**
     * @brief Print the bill for the table's order.
     */
    void printBill();

    /**
     * @brief Get the size or capacity of the table.
     * @return The table size.
     */
    int getTableSize();

    /**
     * @brief Serve the order associated with the table.
     * @details This method is called when the order is ready to be served.
    */
    void serve();

    /**
     * @brief Get the cost per person.
     * @return The cost per person.
    */
    float getCostPerPerson();

    /**
     * @brief Set the cost per person.
     * @param cost The cost per person.
    */
    void setCostPerPerson(int cost);

    /**
     * @brief Get the total cost of the table.
     * @return The total cost of the table.
    */
    float getTableCost();

    /**
     * @brief Set table size
    */
    void setTableSize(int size);

    /**
     * @brief Unset the waiter serving the table.
    */
    void unsetWaiter();
};

#endif  // RESTAURANT_TABLE_H_