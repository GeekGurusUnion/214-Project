#include "WaiterStateAvailable.h"
#include "WaiterStateUnavailable.h"
#include "Waiter.h"

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
    // std::cout << "Waiter is now unavailable." << std::endl;
    waiter->setWaiterState(new WaiterStateUnavailable());
}