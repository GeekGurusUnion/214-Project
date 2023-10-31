#include "WaiterStateUnavailable.h"
#include "WaiterStateAvailable.h"
#include "Waiter.h"

void WaiterStateUnavailable::isAvailable() {
    std::cout << "Waiter is now available." << std::endl;
    waiter->setWaiterState(new WaiterStateAvailable());
}

void WaiterStateUnavailable::isUnavailable() {
    std::cout << "Waiter is already unavailable." << std::endl;
}