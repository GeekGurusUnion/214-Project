#include "ad_OrderAdapter.h"

ad_OrderAdapter::~ad_OrderAdapter() {
    delete restaurantOrder;
}


fa_dish* ad_OrderAdapter::PlaceOrder() {
    auto details = this->getDetails();
    std::string item = details[0];
    std::vector<std::string> customizations(details.begin() + 1, details.end());
    restaurantOrder = new ad_RestaurantOrder(item, customizations);
    return restaurantOrder->prepare();
}
