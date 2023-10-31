#pragma once

#include "MenuItem.h"

class CustomizationHandler
{

protected:
	CustomizationHandler *successor;

public:
	virtual ~CustomizationHandler();
	virtual void HandleExtra(MenuItem* item,  const std::vector<std::string> &customizations) = 0;
};
