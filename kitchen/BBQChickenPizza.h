#pragma once

#include "Pizza.h"
class BBQChickenPizza : public Pizza
{
public:
    BBQChickenPizza()
    {
        this->itemsList = {"base", "tomatoPaste", "cheese", "chicken", "bbqSauce"};
    }
};
