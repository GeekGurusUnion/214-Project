#include "Mediator.h"
#include "KitchenColleague.h"
#include "FloorColleague.h"

void Mediator::notify(Colleague *colleague)
{
    std::cout << "in notify" << std::endl;
    for (int i = 0; i < colleagues.size(); i++)
    {
        std::cout << colleagues.size() << std::endl;
        if (colleagues[i] != colleague)
        {
            colleagues[i]->setOrder(colleague->getOrder());

            colleagues[i]->handleOrder();
            std::cout << "in" << std::endl;
        }
    }
}

void Mediator::addColleague(Colleague *colleague)
{
    colleagues.push_back(colleague);
}