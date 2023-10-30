#pragma once

#include "Burger.h"

class BeefBurger : public Burger
{
public:
    BeefBurger()
    {
        this->itemsList = {"buns", "beefPatty", "cheese", "tomato", "lettuce"};
    }
};
