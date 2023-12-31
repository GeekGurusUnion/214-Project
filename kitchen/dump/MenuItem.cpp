#include "MenuItem.h"

MenuItem::~MenuItem()
{
}

void MenuItem::addComponent(const std::string &component)
{
	itemsList.push_back(component);
}

void MenuItem::removeComponent(const std::string &component)
{
	itemsList.erase(std::remove(itemsList.begin(), itemsList.end(), component), itemsList.end());
}
