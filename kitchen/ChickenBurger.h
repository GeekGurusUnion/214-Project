#pragma once

#include "Burger.h"

class ChickenBurger : public Burger
{

public:
    ChickenBurger()
    {
        this->itemsList = {"buns", "ChickenPatty", "cheese", "tomato", "lettuce"};
    }
};
