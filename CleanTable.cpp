#include "CleanTable.h"
#include "Waiter.h" // Include the header file for Waiter class

CleanTable::CleanTable(Waiter* waiter) {
    this->waiter = waiter;
}

void CleanTable::execute(RestaurantTable* rt, MenuItem* m = nullptr) {
    this->waiter->cleanUp(rt);
}