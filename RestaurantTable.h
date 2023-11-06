#ifndef RESTAURANT_TABLE_H_
#define RESTAURANT_TABLE_H_

/**
 * @file RestaurantTable.h
 * @brief Definition of the RestaurantTable class.
 */

/**
 * @class RestaurantTable
 * @brief Represents a restaurant table with various functionalities.
 *
 * This class represents a restaurant table that can change states, have an associated waiter,
 * manage orders, and notify the waiter of various actions.
 */

// ConcreteSubject (Observer)
// Context (State)
// Invoker (Command)
// ConcreteAggregate (Iterator)

#include "StateEmpty.h"

// #include "Table.h"

class Waiter;
class TableObserver;

#include "Order.h"
class Order;

#include "ConfirmOrder.h"
#include "TakeOrder.h"
#include "GenerateBill.h"
#include "CustomizeOrder.h"

#include "TableObserver.h"

#include "TableIterator.h"
#include <iostream> 

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
     * @brief Transition the table to the "Empty" state.
     */
    void empty();

    /**
     * @brief Notify the waiter of an action.
     * @param action The action to notify the waiter about.
     * @param isItem Indicates whether the action is related to a menu item.
     */
    void notifyWaiter(std::string action, bool isItem);     /// assuming only one waiter helps a table

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
     * @brief Confirm the order associated with the table.
     */
    void confirmOrder();

    /**
     * @brief Welcome the waiter to the table.
     */
    void welcomeWaiter();

    /**
     * @brief Add an item to the order associated with the table.
     * @param item The name of the menu item to add to the order.
     */
    void addToOrder(std::string item);

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
     * @brief Calculate the bill for the table's order.
     * @return The total bill amount.
     */
    float calculateBill();

    /**
     * @brief Print the bill for the table's order.
     */
    void printBill();

    /**
     * @brief Get the size or capacity of the table.
     * @return The table size.
     */
    int getTableSize();
};

#endif  // RESTAURANT_TABLE_H_
