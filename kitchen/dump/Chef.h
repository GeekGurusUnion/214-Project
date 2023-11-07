#pragma once

#include "MenuItem.h"

class Chef
{

// private:
// 	MenuItem *item;

public:
	virtual ~Chef();
	virtual MenuItem *prepareItem(const std::string &item) = 0;
};
