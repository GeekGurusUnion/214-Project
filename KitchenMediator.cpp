#include "KitchenColleague.h"
#include "Mediator.h"
#include "Waiter.h"

KitchenColleague::KitchenColleague(Mediator *mediator) : Colleague(mediator)
{
    this->mediator->addColleague(this);
}

void KitchenColleague::handleOrder()
{
    for (auto &item : this->getOrder()->getItems())
    {
        std::vector<std::string> floorOrder = {""};

        floorOrder.push_back(item->getName());

        for (auto &cus : item->getCustomizations()){
            floorOrder.push_back(cus);
        }

        std::cout << "Handle order" << std::endl;

        std::cout << this->getOrder()->getTable()->getWaiter()->getName() << std::endl;
        // this->orderAdapter = new ad_OrderAdapter(floorOrder);
        // fa_dish* dish = orderAdapter->PlaceOrder();

        // std::cout << dish->getDescription() << std::endl;
    }
}