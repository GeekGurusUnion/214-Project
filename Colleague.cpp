#include "Colleague.h"

Colleague::Colleague(Mediator* mediator) {
    this->mediator = mediator;
    mediator->addColleague(this);
}

void Colleague::changed() {
    mediator->notify(this);
}

void Colleague::setOrder(Order* order) {
    this->order = order;
}

Order* Colleague::getOrder() {
    return this->order;
}