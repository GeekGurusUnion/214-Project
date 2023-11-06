#include "Mediator.h"
#include "KitchenColleague.h"
#include "FloorColleague.h"

void Mediator::notify(Colleague* colleague) {
    for (int i = 0; i < colleagues.size(); i++) {
        if (colleagues[i] != colleague) {
            // colleague->setOrder(colleague->getOrder());
            colleagues[i]->setOrder(colleague->getOrder());

            if (KitchenColleague* kitchen = dynamic_cast<KitchenColleague*>(colleagues[i])){
                kitchen->handleOrder();
            } else if (FloorColleague* floor = dynamic_cast<FloorColleague*>(colleagues[i])) {
                floor->handleOrder();
            } else {
                std::cout << "Mediator: Unknown colleague type.\n";
            }
        }
    }
}

void Mediator::addColleague(Colleague* colleague) {
    colleagues.push_back(colleague);
}