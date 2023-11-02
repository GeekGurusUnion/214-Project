#pragma once

#include <vector>
#include <string>

#include "BurgerChef.h"
#include "PizzaChef.h"
#include "AddGarlic.h"

class headChef
{
public:
    headChef();
    ~headChef();
    void setOrder(const std::string &item, const std::vector<std::string> &customizations);
    MenuItem* prepareItem();

private:
    std::string item;
    std::vector<std::string> customizations;
    BurgerChef* burgerChef;
    PizzaChef* pizzaChef;
    CustomizationHandler *customizationHandler;
};
