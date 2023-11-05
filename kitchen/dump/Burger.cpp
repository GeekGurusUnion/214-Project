#include "Burger.h"

Burger::~Burger()
{
}

std::string Burger::getDescription() const
{
    std::string description = "Burger with: ";
    for (const auto &item : this->itemsList)
    {
        description += item + ", ";
    }
    return description.substr(0, description.length() - 2);
}