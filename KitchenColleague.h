#ifndef KITCHEN_COLLEAGUE_H
#define KITCHEN_COLLEAGUE_H

// ConcreteColleague

#include "Colleague.h"

class KitchenColleague : public Colleague {
    public:
        KitchenColleague(Mediator* mediator);
};

#endif // KITCHEN_COLLEAGUE_H
