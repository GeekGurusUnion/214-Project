#include "KitchenColleague.h"
#include "Mediator.h"
#include "Waiter.h"
#include "ad_OrderAdapter.h"
#include "si_headChef.h"

KitchenColleague::KitchenColleague(Mediator *mediator) : Colleague(mediator)
{
    this->mediator->addColleague(this);
}

void KitchenColleague::handleOrder()
{
    for (auto &item : this->getOrder()->getItems())
    {
        std::vector<std::string> floorOrder = {item->getName()};

        for (auto &cus : item->getCustomizations())
        {
            floorOrder.push_back(cus);
        }

        std::cout << "Handle order" << std::endl;

        std::cout << this->getOrder()->getTable()->getWaiter()->getName() << std::endl;
        ad_OrderAdapter floor(floorOrder);

        fa_dish *dish = floor.PlaceOrder();

        std::cout << dish->getDescription() << std::endl;
    }
}