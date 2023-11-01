#include "WaiterStateUnavailable.h"
#include "WaiterStateAvailable.h"
#include "Waiter.h"

WaiterStateUnavailable::WaiterStateUnavailable(Waiter* waiter) : WaiterState(waiter) {}

bool WaiterStateUnavailable::isAvailable() {
    // std::cout << "Waiter is now available." << std::endl;
    return false;
}

bool WaiterStateUnavailable::isUnavailable() {
    // std::cout << "Waiter is already unavailable." << std::endl;
    return true;
}

void WaiterStateUnavailable::setAvailable() {
    // std::cout << "Waiter is now available." << std::endl;
    waiter->setWaiterState(new WaiterStateAvailable(waiter));
}

void WaiterStateUnavailable::setUnavailable() {
    std::cout << "Waiter is already unavailable." << std::endl;
}