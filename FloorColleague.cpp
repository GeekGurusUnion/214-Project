#include "FloorColleague.h"
#include "Mediator.h"

FloorColleague::FloorColleague(Mediator* mediator) : Colleague(mediator) {
    this->mediator->addColleague(this);
}