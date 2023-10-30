#pragma once

#include <vector>
#include <string>
#include <algorithm>

// #include "CustomizationHandler.h"

class MenuItem
{

protected:
	std::vector<std::string> itemsList;
	// CustomizationHandler *customizationHandler;

public:
	// virtual ~MenuItem();
	void customize();

	void addComponent(const std::string &component);

	void removeComponent(const std::string &component);

	virtual std::string getDescription() const = 0;
};
