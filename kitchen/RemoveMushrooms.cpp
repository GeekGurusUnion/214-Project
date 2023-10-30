#include "RemoveMushrooms.h"

RemoveMushrooms::RemoveMushrooms(){
	this->successor = NULL;
}
void RemoveMushrooms::HandleExtra(MenuItem* item,  const std::vector<std::string> &customizations) {
	int count = std::count(customizations.begin(), customizations.end(), "NoMushrooms");

	if (count > 0){
		item->addComponent("No Mushrooms");
	}

	if (successor != NULL){
		successor->HandleExtra(item, customizations);
	}
}
