#pragma once

#include "CustomizationHandler.h"
#include "AddExtraCheese.h"

class AddGarlic : public CustomizationHandler {


public:
	AddGarlic();
	void HandleExtra(MenuItem* item,  const std::vector<std::string> &customizations);
};

