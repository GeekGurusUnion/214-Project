#include "TakeOrder.h"

TakeOrder::TakeOrder(Waiter* waiter) {
    this->waiter = waiter;
}

void TakeOrder::execute() {
    this->waiter->placeOrder();
}