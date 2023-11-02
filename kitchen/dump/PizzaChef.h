#pragma once

#include "Chef.h"
#include "BBQChickenPizza.h"
#include "HawaiianPizza.h"
#include "PepperoniPizza.h"

class PizzaChef : public Chef
{

public:
	~PizzaChef() override;
	MenuItem *prepareItem(const std::string &item);
};
