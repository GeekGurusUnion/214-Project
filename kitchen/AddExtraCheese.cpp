#include "AddExtraCheese.h"

AddExtraCheese::AddExtraCheese(){
	this->successor = new RemoveMushrooms();
}

void AddExtraCheese::HandleExtra(MenuItem* item,  const std::vector<std::string> &customizations) {
	int count = std::count(customizations.begin(), customizations.end(), "ExtraCheese");

	if (count > 0)
	{
		item->addComponent("Extra cheese");
	}

	if (successor != NULL)
	{
		successor->HandleExtra(item, customizations);
	}
}
