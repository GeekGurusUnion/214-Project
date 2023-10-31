#ifndef KITCHEN_COLLEAGUE_H
#define KITCHEN_COLLEAGUE_H

#include "Colleague.h"

// ConcreteColleague

class KitchenColleague : public Colleague {
    public:
        KitchenColleague(Mediator* mediator);
};

#endif // KITCHEN_COLLEAGUE_H
