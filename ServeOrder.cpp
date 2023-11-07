#include "ServeOrder.h"
#include "RestaurantTable.h"
#include "Waiter.h"

ServeOrder::ServeOrder(Waiter* waiter, RestaurantTable* rt) : Command(waiter) {
    table = rt;
}

void ServeOrder::execute(RestaurantTable* rt, MenuItem* menuItem) {
    waiter->serveOrder(table);
}