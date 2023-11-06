#ifndef TABLE_OBSERVER_H
#define TABLE_OBSERVER_H

/**
 * @file TableObserver.h
 * @brief Definition of the TableObserver class.
 */

/**
 * @class TableObserver
 * @brief Represents a concrete observer for monitoring changes in a RestaurantTable.
 *
 * This class is a concrete implementation of the Observer interface,
 * responsible for receiving and processing updates related to a RestaurantTable.
 */

// ConcreteObserver (Observer)

#include "State.h"
class RestaurantTable;
class Facade;

class TableObserver {
public:
    /**
     * @brief Update the observer with changes in the RestaurantTable.
     * @param t Pointer to the RestaurantTable being observed.
     * @param item The name of the menu item added or removed.
     * @param customization The customization applied to the menu item (if any).
     * @param isItem Indicates whether an item was added (true) or removed (false).
     * @param facade Pointer to the Facade object.
     * @param count The number of tables to merge.
     */
    void update(RestaurantTable* table, std::string item, std::string customization, bool isItem, Facade* facade, int count);
};

#endif // TABLE_OBSERVER_H
