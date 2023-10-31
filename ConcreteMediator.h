#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

// ConcreteMediator

#include "Mediator.h"
#include "FloorColleague.h"

class ConcreteMediator : public Mediator {
    public:
        void notify(Colleague* colleague);
};

#endif // CONCRETEMEDIATOR_H
