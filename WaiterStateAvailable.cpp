#include "WaiterStateAvailable.h"

void WaiterStateAvailable::isAvailable() {
    std::cout << "Waiter is already available." << std::endl;
}

void WaiterStateAvailable::isUnavailable() {
    std::cout << "Waiter is now unavailable." << std::endl;
    waiter->setWaiterState(new WaiterStateUnavailable());
}