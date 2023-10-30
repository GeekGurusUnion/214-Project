#include "BurgerChef.h"

MenuItem *BurgerChef::prepareItem(const std::string &item)
{
	if (item == "beefBurger")
	{
		return new BeefBurger();
	}
	else if (item == "doubleBurger")
	{
		return new DoubleBurger();
	}
	else if (item == "chickenBurger")
	{
		return new ChickenBurger();
	}
	else
	{
		return new BeefBurger();
	}
}
