#include "headChef.h"

headChef::headChef()
{
    this->burgerChef = new BurgerChef();
    this->pizzaChef = new PizzaChef();
}

headChef::~headChef()
{
    delete this->burgerChef;
    delete this->pizzaChef;

    if (customizationHandler != NULL){
        delete customizationHandler;
    }
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