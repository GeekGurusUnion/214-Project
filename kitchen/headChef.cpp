#include "headChef.h"

headChef::headChef()// : item(item), customizations(customizations)
{
    this->burgerChef = new BurgerChef();
    this->pizzaChef = new PizzaChef();
}

void headChef::setOrder(const std::string &item, const std::vector<std::string> &customizations){
    this->item = item;
    this->customizations = customizations;
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