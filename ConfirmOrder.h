#ifndef CONFIRMORDER_H_
#define CONFIRMORDER_H_

#include "Command.h"
#include "Waiter.h"

class ConfirmOrder : public Command {
    public:
        ConfirmOrder(Waiter* waiter);
        void execute();
    private:
        Waiter* waiter;
};

#endif // CONFIRMORDER_H_