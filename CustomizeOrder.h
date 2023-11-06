#ifndef CUSTOMIZE_ORDER_H
#define CUSTOMIZE_ORDER_H
// ConcreteCommand (Command)
/**
 * @file CustomizeOrder.h
 * @brief Declaration of the CustomizeOrder class, a concrete implementation of the Command pattern.
 */

#include "Command.h"
class Waiter;
class RestaurantTable;
class MenuItem;

/**
 * @class CustomizeOrder
 * @brief A concrete command for customizing an order with specific customization details.
 *
 * CustomizeOrder is a specific command that represents the action of customizing an order at a restaurant.
 * It is associated with a particular Waiter and allows customization of a given RestaurantTable's order.
 */
class CustomizeOrder : public Command {
public:
    /**
     * @brief Constructor for the CustomizeOrder class.
     * @param waiter A pointer to the Waiter issuing the customization command.
     */
    CustomizeOrder(Waiter* waiter);

    /**
     * @brief Execute the customization of an order with specific customization details.
     * @param rt A pointer to the RestaurantTable for which the order is being customized.
     * @param m A string representing the name of the MenuItem being customized.
     * @param customization A string specifying the customization details.
     */
    void execute(RestaurantTable* rt, std::string m, std::string customization);

    /**
     * @brief Dummy execution method for customization with MenuItem (not used).
     * @param rt A pointer to the RestaurantTable for which the order is being customized.
     * @param m A pointer to the MenuItem (not used in this method).
     */
    void execute(RestaurantTable* rt, MenuItem* m) {}
};

#endif // CUSTOMIZE_ORDER_H

