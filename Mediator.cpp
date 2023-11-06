#include "Mediator.h"
#include "KitchenColleague.h"

void Mediator::notify(Colleague* colleague) {
    for (int i = 0; i < colleagues.size(); i++) {
        if (colleagues[i] != colleague) {
            colleague->setOrder(colleague->getOrder());
            colleagues[i]->setOrder(colleague->getOrder());

            if (KitchenColleague* kitchen = dynamic_cast<KitchenColleague*>(colleagues[i])){
                kitchen->handleOrder();
            }
        }
    }
}

void Mediator::addColleague(Colleague* colleague) {
    colleagues.push_back(colleague);
}