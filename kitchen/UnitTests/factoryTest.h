#pragma once

#include "FactoryCode/fa_dishFactory.h"
#include "FactoryCode/fa_Pizza.h"

//Test pizza factory
std::string testPizza(const std::string &item, const std::vector<std::string> &customizations);

// Test burger factory
std::string testBurger(const std::string &item, const std::vector<std::string> &customizations);