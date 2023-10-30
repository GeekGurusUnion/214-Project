#include "PizzaChef.h"

MenuItem* PizzaChef::prepareItem(const std::string &item) {
	if (item == "pepperoniPizza")
	{
		return new PepperoniPizza();
	}
	else if (item == "hawaiianPizza")
	{
		return new HawaiianPizza();
	}
	else if (item == "bbqChickenPizza")
	{
		return new BBQChickenPizza();
	}
	else
	{
		return new PepperoniPizza();
	}
}
