#include "RestaurantOrder.h"

RestaurantOrder::~RestaurantOrder()
{
}

std::string RestaurantOrder::getItem() const
{
    return item;
}

std::vector<std::string> RestaurantOrder::getCustomizations() const
{
    return customizations;
}
