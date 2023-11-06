#ifndef CONFIRMORDER_H
#define CONFIRMORDER_H
// ConcreteCommand (Command)
/**
 * @file ConfirmOrder.h
 * @brief Declaration of the ConfirmOrder class, a concrete implementation of the Command pattern.
 */

#include "Command.h"
class Waiter;
class RestaurantTable;
class MenuItem;
class FloorColleague;
class Colleague;

/**
 * @class ConfirmOrder
 * @brief A concrete command for confirming an order with a specific FloorColleague.
 *
 * ConfirmOrder is a specific command that represents the action of confirming an order at a restaurant.
 * It is associated with a particular Waiter and a specific FloorColleague, and it executes this action
 * for a given RestaurantTable and MenuItem.
 */
class ConfirmOrder : public Command {
private:
    Colleague* floorColleague; ///< A pointer to the FloorColleague responsible for confirming the order.

public:
    /**
     * @brief Constructor for the ConfirmOrder class.
     * @param waiter A pointer to the Waiter issuing the confirmation command.
     * @param floorColleague A pointer to the FloorColleague responsible for confirming the order.
     */
    ConfirmOrder(Waiter* waiter, Colleague* floorColleague);

    /**
     * @brief Execute the confirmation of an order.
     * @param rt A pointer to the RestaurantTable for which the order is being confirmed.
     * @param m A pointer to the MenuItem that is being confirmed.
     */
    void execute(RestaurantTable* rt, MenuItem* m);
};

#endif // CONFIRMORDER_H

