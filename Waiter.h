#ifndef WAITER_H
#define WAITER_H

/**
 * @file Waiter.h
 * @brief Definition of the Waiter class.
 */

/**
 * @class Waiter
 * @brief Represents a Waiter in a restaurant.
 *
 * This class represents a Waiter who takes orders, serves tables, and manages orders.
 */

// Receiver (Command)
// Context (State)
#include <iostream>
#include "WaiterState.h"
#include "WaiterStateAvailable.h"
#include "WaiterStateUnavailable.h"
#include "WaiterIterator.h"
#include "Order.h"
#include "FloorColleague.h"

class Waiter {
private:
    /**
     * @var name
     * @brief The name of the Waiter.
     */
    std::string name;

    /**
     * @var state
     * @brief The current state of the Waiter.
     */
    WaiterState* state;

    /**
     * @var tables
     * @brief A vector of RestaurantTable pointers associated with the Waiter.
     */
    std::vector<RestaurantTable*> tables = std::vector<RestaurantTable*>();

    /**
     * @var busyOrders
     * @brief The number of currently busy orders.
     */
    int busyOrders = 0;

    /**
     * @var totalOrders
     * @brief The total number of orders the Waiter is expected to handle.
     */
    int totalOrders;

    /**
     * @var menu
     * @brief A vector of MenuItem pointers representing the menu items available.
     */
    std::vector<MenuItem*> menu = std::vector<MenuItem*>();

    /**
     * @var cO
     * @brief A Command pointer for confirming orders.
     */
    Command* cO = nullptr;

    /**
     * @var tO
     * @brief A Command pointer for taking orders.
     */
    Command* tO = nullptr;

    /**
     * @var gB
     * @brief A Command pointer for generating bills.
     */
    Command* gB = nullptr;

    /**
     * @var aC
     * @brief A Command pointer for adding customizations.
     */
    Command* aC = nullptr;

public:
    /**
     * @brief Constructor for Waiter.
     * @param name The name of the Waiter.
     * @param totalOrders The total number of orders the Waiter is expected to handle.
     * @param fc A pointer to the FloorColleague associated with the Waiter.
     */
    Waiter(std::string name, int totalOrders, FloorColleague *fc);

    /**
     * @brief Destructor for Waiter.
     */
    ~Waiter();

    /**
     * @brief Set the Waiter's state.
     * @param state Pointer to the new WaiterState.
     */
    void setWaiterState(WaiterState* state);

    /**
     * @brief Add an item to the order for a RestaurantTable.
     * @param rt Pointer to the RestaurantTable.
     * @param m Name of the menu item to add.
     */
    void addItem(RestaurantTable* rt, std::string m);

    /**
     * @brief Confirm the order for a RestaurantTable.
     * @param rt Pointer to the RestaurantTable.
     */
    void confirmOrder(RestaurantTable* rt);

    /**
     * @brief Add an order for a RestaurantTable.
     * @param rt Pointer to the RestaurantTable.
     */
    void addOrder(RestaurantTable* rt);

    /**
     * @brief Add customization to an order for a RestaurantTable.
     * @param rt Pointer to the RestaurantTable.
     * @param name Name of the menu item.
     * @param customization Customization to add.
     */
    void addCustomization(RestaurantTable* rt, std::string name, std::string customization);

    /**
     * @brief Generate a bill for a RestaurantTable.
     * @param rt Pointer to the RestaurantTable.
     */
    void generateBill(RestaurantTable* rt);

    /**
     * @brief Get the order for a RestaurantTable.
     * @param rt Pointer to the RestaurantTable.
     * @return Pointer to the Order.
     */
    Order* getOrder(RestaurantTable* rt);

    /**
     * @brief Check if the Waiter is available.
     * @return True if the Waiter is available, false otherwise.
     */
    bool isAvailable();

    /**
     * @brief Get the name of the Waiter.
     * @return The name of the Waiter.
     */
    std::string getName() const;

    /**
     * @brief Get the menu item by name.
     * @param name Name of the menu item.
     * @return Pointer to the MenuItem.
     */
    MenuItem *getMenuItem(std::string name);

    /**
     * @brief Get the number of currently busy orders.
     * @return The number of busy orders.
     */
    int getBusyOrders() const;

    /**
     * @note The following functions are intended for testing purposes.
     */
    // * testing * //

    /**
     * @brief Get the total number of orders the Waiter is expected to handle.
     * @return The total number of orders.
     */
    int getTotalOrders() const;

    /**
     * @brief Get the current WaiterState.
     * @return Pointer to the WaiterState.
     */
    WaiterState* getState() const;

    /**
     * @brief Get the vector of RestaurantTable pointers associated with the Waiter.
     * @return A vector of RestaurantTable pointers.
     */
    std::vector<RestaurantTable*> getTables() const;

    /**
     * @brief Get the vector of MenuItem pointers representing the menu items available.
     * @return A vector of MenuItem pointers.
     */
    std::vector<MenuItem*> getMenu() const;

    /**
     * @brief Get the Command pointer for confirming orders.
     * @return Pointer to the Command for confirming orders.
     */
    Command* getCO() const;

    /**
     * @brief Get the Command pointer for taking orders.
     * @return Pointer to the Command for taking orders.
     */
    Command* getTO() const;

    /**
     * @brief Set the Waiter's state (for testing purposes).
     * @param state Pointer to the WaiterState.
     */
    void setState(WaiterState* state);

    // * end of testing * //

    /**
     * @brief Serve a RestaurantTable.
    */
    void serveOrder(RestaurantTable* rt);
};

#endif // WAITER_H