#pragma once
#include "order.h"

class adapter {
public:
    static KitchenOrder adapt(const FloorOrder &floorOrder) {
        auto details = floorOrder.getDetails();
        std::string item = details[0];
        std::vector <std::string> customizations(details.begin() + 1, details.end());
        return KitchenOrder(item, customizations);
    }
};
