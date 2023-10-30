#ifndef TAKEORDER_H_
#define TAKEORDER_H_

#include "Command.h"
#include "Waiter.h"

class TakeOrder : public Command {
    public:
        TakeOrder(Waiter* waiter);
        void execute();
    private:
        Waiter* waiter;
};

#endif // TAKEORDER_H_