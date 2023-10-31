#include "TakeOrder.h"
#include "Order.h"
#include "Waiter.h"

TakeOrder::TakeOrder(Waiter* waiter) {
    this->waiter = waiter;
}

void TakeOrder::execute(RestaurantTable* rt, MenuItem* m) {
    Order* o = this->waiter->getOrder(rt);
    if (o == nullptr) {
        std::cout << "TakeOrder: No order found for table " << rt << ".\n";
        return;
    }
    this->waiter->addItem(rt, m);
}