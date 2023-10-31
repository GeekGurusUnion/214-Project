#include "Mediator.h"

void Mediator::notify(Colleague* colleague) {
    for (int i = 0; i < colleagues.size(); i++) {
        if (colleagues[i] != colleague) {
            colleague->setOrder(colleague->getOrder());
        }
    }
}

void Mediator::addColleague(Colleague* colleague) {
    colleagues.push_back(colleague);
}