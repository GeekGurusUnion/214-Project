#include "FloorColleague.h"
#include "Mediator.h"

FloorColleague::FloorColleague(Mediator* mediator) : Colleague(mediator) {
    this->mediator->addColleague(this);
}

FloorColleague::~FloorColleague() {
    delete this->serveOrderCommand;
}

void FloorColleague::handleOrder() {
    if (this->serveOrderCommand != nullptr) {
        delete this->serveOrderCommand;
    }
    this->serveOrderCommand = new ServeOrder(this->getOrder()->getTable()->getWaiter(), this->getOrder()->getTable());
    serveOrderCommand->execute(this->getOrder()->getTable(), nullptr);
}