#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Colleague.h"

class Mediator {
    public:
        virtual void notify(Colleague* colleague) = 0;
};

#endif // MEDIATOR_H
