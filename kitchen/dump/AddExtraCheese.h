#pragma once

#include "CustomizationHandler.h"
#include "RemoveMushrooms.h"

class AddExtraCheese : public CustomizationHandler
{

public:
	AddExtraCheese();
	~AddExtraCheese() override;
	void HandleExtra(MenuItem *item, const std::vector<std::string> &customizations);
};
