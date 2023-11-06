#ifndef SPLIT_BILL_H
#define SPLIT_BILL_H

#include "Command.h"

/**
 * @brief The SplitBill class represents a command to split the bill of a restaurant table.
 */
class SplitBill : public Command {
    public:
        /**
         * @brief Constructs a new SplitBill object with the given waiter.
         * 
         * @param w The waiter responsible for splitting the bill.
         */
        SplitBill(Waiter* w);

        /**
         * @brief Executes the SplitBill command on the given restaurant table with the given count.
         * 
         * @param rt The restaurant table to split the bill for.
         * @param count The number of ways to split the bill.
         */
        void execute(RestaurantTable* rt, double count);
};

#endif // SPLIT_BILL_H