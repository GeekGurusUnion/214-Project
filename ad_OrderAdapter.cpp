#include "ad_OrderAdapter.h"

ad_OrderAdapter::ad_OrderAdapter(const std::vector<std::string> &details) : ad_FloorOrder(details) {
    auto detail = this->getDetails();
    std::string item = detail[0];
    std::vector<std::string> customizations(detail.begin() + 1, detail.end());
    restaurantOrder = new ad_RestaurantOrder(item, customizations);
}

ad_OrderAdapter::~ad_OrderAdapter() {
    delete restaurantOrder;
}


fa_dish* ad_OrderAdapter::PlaceOrder() {
    return restaurantOrder->prepare();
}
