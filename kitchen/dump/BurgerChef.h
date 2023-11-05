#pragma once

#include "Chef.h"
#include "BeefBurger.h"
#include "ChickenBurger.h"
#include "DoubleBurger.h"

class BurgerChef : public Chef {
public:
	~BurgerChef() override;
	MenuItem* prepareItem(const std::string &item);
};

