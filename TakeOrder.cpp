#include "TakeOrder.h"
#include "Order.h"
#include "Waiter.h"

TakeOrder::TakeOrder(Waiter* waiter) : Command(waiter) {}

void TakeOrder::execute(RestaurantTable* rt, MenuItem* m) {
    if (this->waiter->getOrder(rt) == nullptr) {
        std::cout << "TakeOrder: No order found for table " << rt << ".\n";
        return;
    }
    if (m != nullptr) {
        this->waiter->addItem(rt, m);
    }
}