#pragma once

#include "MenuItem.h"

class Pizza : public MenuItem
{
public:
    ~Pizza() override;
    std::string getDescription() const;
};
