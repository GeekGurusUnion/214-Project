#ifndef SERVE_ORDER_H
#define SERVE_ORDER_H

#include "Command.h"

class Waiter;
class RestaurantTable;

/**
 * @class ServeOrder
 * @brief A class representing a command to serve an order for a specific table.
 * 
 * This class inherits from the Command class and implements the execute method to serve an order for a specific table.
 */
/**
 * @file ServeOrder.h
 * @brief Header file for the ServeOrder class.
 */

/**
 * @brief The ServeOrder class represents a command to serve an order for a RestaurantTable.
 */
class ServeOrder : public Command {
    private:
        RestaurantTable* table; /**< A pointer to the RestaurantTable to serve the order for. */
    public:
        /**
         * @brief Constructs a ServeOrder object with the given Waiter and RestaurantTable.
         * @param waiter A pointer to the Waiter who will serve the order.
         * @param table A pointer to the RestaurantTable to serve the order for.
         */
        ServeOrder(Waiter* waiter, RestaurantTable* table);

        /**
         * @brief Executes the ServeOrder command for the given RestaurantTable and MenuItem.
         * @param rt A pointer to the RestaurantTable to serve the order for.
         * @param menuItem A pointer to the MenuItem to serve.
         */
        void execute(RestaurantTable* rt, MenuItem* menuItem);
};

#endif // SERVE_ORDER_H