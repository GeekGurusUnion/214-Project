#pragma once

#include "Pizza.h"

class HawaiianPizza : public Pizza
{
public:
    HawaiianPizza()
    {
        this->itemsList = {"base", "tomatoPaste", "cheese", "pineapple", "ham"};
    }
};
