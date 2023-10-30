#ifndef CLEANTABLE_H_
#define CLEANTABLE_H_

#include "Command.h"
#include "Waiter.h"

class CleanTable : public Command {
    public:
        CleanTable(Waiter* waiter);
        void execute();
    private:
        Waiter* waiter;
};

#endif // CLEANTABLE_H_