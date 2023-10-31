#include "CleanTable.h"

CleanTable::CleanTable(Waiter* waiter) {
    this->waiter = waiter;
}

void CleanTable::execute(RestaurantTable* rt, MenuItem* m = nullptr) {
    this->waiter->cleanUp(rt);
}