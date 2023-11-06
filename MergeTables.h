#ifndef MERGE_TABLES_H
#define MERGE_TABLES_H

#include "Command.h"
class Facade;

class MergeTables : public Command {
    public:
        MergeTables(Waiter* w);
        void execute(Facade* f, int count);
};

#endif // MERGE_TABLES_H