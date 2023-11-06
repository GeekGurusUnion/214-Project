#include "WaiterStateUnavailable.h"
#include "WaiterStateAvailable.h"
#include "Waiter.h"

WaiterStateUnavailable::WaiterStateUnavailable(Waiter* waiter) : WaiterState(waiter) {}

bool WaiterStateUnavailable::isAvailable() {
    return false;
}

bool WaiterStateUnavailable::isUnavailable() {
    return true;
}

void WaiterStateUnavailable::setAvailable() {
    waiter->setWaiterState(new WaiterStateAvailable(waiter));
}

void WaiterStateUnavailable::setUnavailable() {
    std::cout << "Waiter is already unavailable." << std::endl;
}

// * testing * //
WaiterState* WaiterStateUnavailable::getThis() {
    return this;
}