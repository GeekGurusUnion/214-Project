#ifndef CLEANTABLE_H
#define CLEANTABLE_H

// ConcreteCommand (Command)

#include "Command.h"
#include "Waiter.h"

class CleanTable : public Command {
    public:
        CleanTable(Waiter* waiter);
        void execute();
    private:
        Waiter* waiter;
};

#endif // CLEANTABLE_H
