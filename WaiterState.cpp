#include "WaiterState.h"

WaiterState::WaiterState(Waiter* waiter) {
    this->waiter = waiter;
}

void WaiterState::setWaiter(Waiter* waiter) {
    this->waiter = waiter;
}