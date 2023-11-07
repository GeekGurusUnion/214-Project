#ifndef MERGE_TABLES_H
#define MERGE_TABLES_H
// ConcreteCommand (Command)

/**
 * @file MergeTables.h
 * @brief Declaration of the MergeTables class representing a command to merge tables in a restaurant.
 */

#include "Command.h"
//Forward declaration
class Facade;

/**
 * @class MergeTables
 * @brief A class representing a command to merge tables in a restaurant.
 * 
 * MergeTables is a concrete command in the Command design pattern.
 */

class MergeTables : public Command {
    public:
        /**
         * @brief Constructs a new MergeTables object with the given Waiter.
         * 
         * @param w The Waiter object to use for merging tables.
         */
        MergeTables(Waiter* w);

        /**
         * @brief Executes the MergeTables command on the given Facade object.
         * 
         * @param f The Facade object to execute the command on.
         * @param count The number of tables to merge.
         */
        void execute(Facade* f, int count);
};

#endif // MERGE_TABLES_H