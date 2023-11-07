#ifndef TAKEORDER_H
#define TAKEORDER_H
// ConcreteCommand (Command)

/**
 * @file TakeOrder.h
 * @brief Definition of the TakeOrder class.
 */

#include "Command.h"
// Forward declaration
class Waiter;

/**
 * @class TakeOrder
 * @brief Represents a concrete command to take an order from a customer.
 *
 * This class is a concrete implementation of the Command interface,
 * representing the action of taking an order from a customer by a Waiter.
 */

class TakeOrder : public Command {
public:
    /**
     * @brief Constructor for TakeOrder.
     * @param waiter Pointer to the Waiter responsible for taking the order.
     */
    TakeOrder(Waiter* waiter);

    /**
     * @brief Execute the command to take an order.
     * @param rt Pointer to the RestaurantTable where the order is being taken.
     * @param m Pointer to the MenuItem that the customer orders.
     */
    void execute(RestaurantTable* rt, MenuItem* m);
};

#endif // TAKEORDER_H

