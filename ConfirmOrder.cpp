#include "ConfirmOrder.h"
#include "Waiter.h"

ConfirmOrder::ConfirmOrder(Waiter* waiter) : Command(waiter) {}

void ConfirmOrder::execute(RestaurantTable* rt, MenuItem* m = nullptr) {
    waiter->confirmOrder(rt);
}