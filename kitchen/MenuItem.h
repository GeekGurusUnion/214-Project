#pragma once

#include <vector>
#include <string>
#include <algorithm>

class MenuItem
{

protected:
	std::vector<std::string> itemsList;

public:
	// void customize();

	void addComponent(const std::string &component);

	void removeComponent(const std::string &component);

	virtual std::string getDescription() const = 0;
};
