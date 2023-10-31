#pragma once

#include "MenuItem.h"

class Burger : public MenuItem
{
public:
    ~Burger() override;
    std::string getDescription() const;
};
