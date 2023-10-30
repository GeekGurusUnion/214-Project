#ifndef MEDIATOR_H
#define MEDIATOR_H

// Mediator (Mediator) [interface]

#include "Colleague.h"

class Mediator {
    public:
        virtual void notify(Colleague* colleague) = 0;
};

#endif // MEDIATOR_H
