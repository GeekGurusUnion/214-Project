#include "ConfirmOrder.h"
#include "Waiter.h"

ConfirmOrder::ConfirmOrder(Waiter* waiter) {
    this->waiter = waiter;
}

void ConfirmOrder::execute(RestaurantTable* rt, MenuItem* m = nullptr) {
    waiter->confirmOrder(rt);
}