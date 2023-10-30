#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "Mediator.h"

// Colleague (Mediator) [interface]

class Colleague {
    protected:
        Mediator* mediator;
    public:
        Colleague(Mediator* mediator);
        virtual void notify() = 0;
};

#endif // COLLEAGUE_H