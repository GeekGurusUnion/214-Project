#ifndef MERGE_TABLES_H
#define MERGE_TABLES_H

#include "Command.h"
class Facade;

/**
 * @brief The MergeTables class represents a Command that merges tables in a restaurant.
 * 
 * This class inherits from the Command class and implements the execute method to merge tables.
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