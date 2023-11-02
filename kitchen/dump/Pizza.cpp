#include "Pizza.h"

Pizza::~Pizza()
{
}

std::string Pizza::getDescription() const
{
    std::string description = "Pizza with: ";
    for (const auto &item : this->itemsList)
    {
        description += item + ", ";
    }
    return description.substr(0, description.length() - 2);
}