#pragma once
#include "dishFactory.h"

class headchef {
public:
    dish* prepareDish(const KitchenOrder& order) {
        if (order.getItem() == "Burger") {
            burgerFactory burgerFactory;
            return burgerFactory.createDish(order);
        }

        return nullptr;
    }
};
