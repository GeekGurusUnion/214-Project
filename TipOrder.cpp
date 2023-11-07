#include "TipOrder.h"
#include "RestaurantTable.h"

TipOrder::TipOrder(Waiter* w) : Command(w) {}

void TipOrder::execute(RestaurantTable *rt, double tip) {
    rt->getOrder()->addTip(tip);
}