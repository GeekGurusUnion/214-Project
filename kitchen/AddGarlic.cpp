#include "AddGarlic.h"

AddGarlic::AddGarlic()
{
	this->successor = new AddExtraCheese();
}

AddGarlic::~AddGarlic()
{
	if (successor != NULL)
	{
		delete this->successor;
	}
}

void AddGarlic::HandleExtra(MenuItem *item, const std::vector<std::string> &customizations)
{
	int count = std::count(customizations.begin(), customizations.end(), "ExtraGarlic");

	if (count > 0)
	{
		item->addComponent("Extra garlic");
	}

	if (successor != NULL)
	{
		successor->HandleExtra(item, customizations);
	}
}
