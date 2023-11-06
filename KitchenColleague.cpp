#include "KitchenColleague.h"
#include "Mediator.h"
#include "Waiter.h"
#include "ad_OrderAdapter.h"
#include "si_headChef.h"

KitchenColleague::KitchenColleague(Mediator *mediator) : Colleague(mediator)
{
    this->mediator->addColleague(this);
}

KitchenColleague::~KitchenColleague()
{
    delete this->orderAdapter;
}

void KitchenColleague::handleOrder()
{
    std::vector<fa_dish*> dishes = std::vector<fa_dish*>();

    for (auto &item : this->getOrder()->getItems())
    {
        std::vector<std::string> floorOrder = {item->getName()};

        for (auto &cus : item->getCustomizations())
        {
            floorOrder.push_back(cus);
        }

        std::cout << this->getOrder()->getTable()->getWaiter()->getName() << std::endl;
        ad_OrderAdapter floor(floorOrder);

        fa_dish *dish = floor.PlaceOrder();

        dishes.push_back(dish);

        //std::cout << dish->getDescription() << std::endl; // This gets the description of the dish. Contains all the Info of the dish. 
    }

    this->getOrder()->setDishes(dishes);
    this->changed();
}