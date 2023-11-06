#include "ad_RestaurantOrder.h"
#include "si_headChef.h"

ad_RestaurantOrder::ad_RestaurantOrder(const std::string &item, const std::vector<std::string> &customizations)
        : item(item), customizations(customizations) {}

ad_RestaurantOrder::~ad_RestaurantOrder() = default;

std::string ad_RestaurantOrder::getItem() const {
    return item;
}

std::vector<std::string> ad_RestaurantOrder::getCustomizations() const {
    return customizations;
}

fa_dish *ad_RestaurantOrder::prepare() {
    si_headChef *chef = si_headChef::getInstance();
    return chef->prepareDish(*this);
}
