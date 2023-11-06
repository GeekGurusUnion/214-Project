#include "WaiterStateAvailable.h"
#include "WaiterStateUnavailable.h"
#include "Waiter.h"

WaiterStateAvailable::WaiterStateAvailable(Waiter* waiter) : WaiterState(waiter) {}

bool WaiterStateAvailable::isAvailable() {
    return true;
}

bool WaiterStateAvailable::isUnavailable() {
    return false;
}

void WaiterStateAvailable::setAvailable() {
    std::cout << "Waiter is already available." << std::endl;
}

void WaiterStateAvailable::setUnavailable() {
    waiter->setWaiterState(new WaiterStateUnavailable(waiter));
}

// * testing * //

WaiterState* WaiterStateAvailable::getThis() {
    return this;
}

// * end of testing * //
