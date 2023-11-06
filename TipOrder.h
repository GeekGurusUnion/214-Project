#ifndef TIP_ORDER_H
#define TIP_ORDER_H

/** 
 * @brief TipOrder class
 * @details TipOrder class is a concrete command that is used to tip a waiter for a table
*/

/**
 * @file TipOrder.h
 * @brief Definition of the TipOrder class.
*/

#include "Command.h"

/**
 * @class TipOrder
 * @brief A concrete Command that represents a tip order given by a customer to a waiter.
 * 
 * This class inherits from the Command abstract class and implements the execute method.
 * The execute method takes a RestaurantTable and a double representing the tip amount as parameters.
 * When executed, it calls the addTip method of the Waiter passed in the constructor with the given tip amount.
 */
class TipOrder : public Command {
    public:
        /**
         * @brief Constructs a TipOrder object with the given Waiter.
         * 
         * @param w A pointer to the Waiter who will receive the tip order.
         */
        TipOrder(Waiter* w);

        /**
         * @brief Executes the tip order by calling the addTip method of the Waiter with the given tip amount.
         * 
         * @param rt A pointer to the RestaurantTable associated with the tip order.
         * @param tip The amount of the tip.
         */
        void execute(RestaurantTable* rt, double tip);
};

#endif // TIP_ORDER_H