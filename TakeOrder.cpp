#include "TakeOrder.h"
#include "Order.h"
#include "Waiter.h"

TakeOrder::TakeOrder(Waiter* waiter) : Command(waiter) {}

void TakeOrder::execute(RestaurantTable* rt, MenuItem* m) {
    Order* o = rt->getOrder();
    if (o == nullptr) {
        std::cout << "Waiter: No order found for table " << rt << ".\n";
        return;
    }
    o->addItem(m);
}