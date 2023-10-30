#include "ConfirmOrder.h"

ConfirmOrder::ConfirmOrder(Waiter* waiter) {
    this->waiter = waiter;
}

void ConfirmOrder::execute() {
    this->waiter->confirmOrder();
}