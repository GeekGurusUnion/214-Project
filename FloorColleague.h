#ifndef FLOOR_COLLEAGUE_H
#define FLOOR_COLLEAGUE_H

#include "Waiter.h"
#include "Colleague.h"

// ConcreteColleague

class FloorColleague : public Colleague {
    public:
        FloorColleague(Mediator* mediator);
};

#endif // FLOOR_COLLEAGUE_H
