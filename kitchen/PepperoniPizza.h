#pragma once

#include "Pizza.h"

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza()
    {
        this->itemsList = {"base", "TomatoPaste", "cheese", "pepperoni", "mushrooms"};
    }
};
