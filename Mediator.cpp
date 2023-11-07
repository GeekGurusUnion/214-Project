#include "Mediator.h"
#include "KitchenColleague.h"
#include "FloorColleague.h"

void Mediator::notify(Colleague *colleague)
{
    for (int i = 0; i < colleagues.size(); i++)
    {
        if (colleagues[i] != colleague)
        {
            colleagues[i]->setOrder(colleague->getOrder());

            colleagues[i]->handleOrder();
        }
    }
}

void Mediator::addColleague(Colleague *colleague)
{
    colleagues.push_back(colleague);
}