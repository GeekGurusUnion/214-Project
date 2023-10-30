#include "headChef.h"

headChef::headChef(const std::string &item, const std::vector<std::string> &customizations) : item(item), customizations(customizations)
{
    this->burgerChef = new BurgerChef();
    this->pizzaChef = new PizzaChef();
}

MenuItem* headChef::prepareItem()
{
    MenuItem* newItem;

    if (item.find("Burger") != std::string::npos)
    {
        newItem = burgerChef->prepareItem(item);
    }
    else if (item.find("Pizza") != std::string::npos)
    {
        newItem = pizzaChef->prepareItem(item);
    }

    this->customizationHandler = new AddGarlic();

    customizationHandler->HandleExtra(newItem, customizations);

    return newItem;
}