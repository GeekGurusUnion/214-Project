#ifndef TAKEORDER_H
#define TAKEORDER_H

// ConcreteCommand (Command)

#include "Command.h"
#include "Waiter.h"

class TakeOrder : public Command {
    public:
        TakeOrder(Waiter* waiter);
        void execute();
    private:
        Waiter* waiter;
};

#endif // TAKEORDER_H
