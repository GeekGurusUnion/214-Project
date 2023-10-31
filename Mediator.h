#ifndef MEDIATOR_H
#define MEDIATOR_H

// Mediator (Mediator) [interface]

#include "Colleague.h"
#include <vector>

class Mediator {
    private:
        std::vector<Colleague*> colleagues;
    public:
        virtual void notify(Colleague* colleague);
        virtual void addColleague(Colleague* colleague);
};

#endif // MEDIATOR_H
