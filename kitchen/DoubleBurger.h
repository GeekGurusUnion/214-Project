#pragma once

#include "Burger.h"

class DoubleBurger : public Burger
{
public:
    DoubleBurger()
    {
        this->itemsList = {"buns", "DoublePatty", "cheese", "tomato", "lettuce"};
    }
};
