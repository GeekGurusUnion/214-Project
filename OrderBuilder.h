#ifndef ORDER_BUILDER_H
#define ORDER_BUILDER_H

#include "Order.h"

class OrderBuilder {
  private:
    Order* order;

  public:
    OrderBuilder();
    OrderBuilder addItem(MenuItem* item);
    OrderBuilder setStatus(bool status);
    Order* build();
};

#endif // ORDER_BUILDER_H