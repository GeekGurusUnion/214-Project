#include "KitchenColleague.h"
#include "Mediator.h"

KitchenColleague::KitchenColleague(Mediator* mediator) : Colleague(mediator) {
    this->mediator->addColleague(this);
}