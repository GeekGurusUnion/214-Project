#include "RestaurantOrder.h"

void RestaurantOrder::PrepareOrder()
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

// void RestaurantOrder::UpdateOrder(std::vector<std::string> contains, std::vector<std::string> customizations) {

// }
