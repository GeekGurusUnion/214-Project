#pragma once
#include "dish.h"
#include "order.h"

class dishFactory {
public:
    virtual ~dishFactory() {}
    virtual dish* createDish(const KitchenOrder& order) = 0;
};

class burgerFactory : public dishFactory {
public:
    dish* createDish(const KitchenOrder& order) override;
};
