#pragma once

#include "CustomizationHandler.h"

class RemoveMushrooms : public CustomizationHandler
{

public:
	RemoveMushrooms();
	~RemoveMushrooms() override;
	void HandleExtra(MenuItem *item, const std::vector<std::string> &customizations);
};
