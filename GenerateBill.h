#ifndef GENERATE_BILL_H
#define GENERATE_BILL_H
//Concrete Command (Command)
/**
 * @file GenerateBill.h
 * @brief Declaration of the GenerateBill class, a concrete implementation of the Command pattern.
 */

#include "Command.h"
class Waiter;

/**
 * @class GenerateBill
 * @brief A concrete command for generating a bill for a customer's order.
 *
 * GenerateBill is a specific command that represents the action of generating a bill for a customer's
 * order in a restaurant. It is associated with a particular Waiter and executes this action for a
 * specific RestaurantTable and MenuItem.
 */
class GenerateBill : public Command {
public:
    /**
     * @brief Constructor for the GenerateBill class.
     * @param waiter A pointer to the Waiter responsible for generating the bill.
     */
    GenerateBill(Waiter* waiter);

    /**
     * @brief Execute the generation of a bill for a specific order.
     * @param rt A pointer to the RestaurantTable for which the bill is being generated.
     * @param m A pointer to the MenuItem for which the bill is being generated.
     */
    void execute(RestaurantTable* rt, MenuItem* m);
};

#endif // GENERATE_BILL_H
