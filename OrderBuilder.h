#ifndef ORDER_BUILDER_H
#define ORDER_BUILDER_H

#include "Order.h"
#include "Builder.h"

class OrderBuilder : public Builder {
    private:
        Order* order = new Order();
    public:
        OrderBuilder addItem(MenuItem* item);
        OrderBuilder setStatus(bool status); // order confirmed or not
};

#endif // ORDER_BUILDER_H