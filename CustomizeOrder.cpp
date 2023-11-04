#include "CustomizeOrder.h"
#include "Waiter.h"

CustomizeOrder::CustomizeOrder(Waiter *waiter) : Command(waiter) {}

void CustomizeOrder::execute(RestaurantTable *rt, std::string m, std::string customization) {
    rt->getOrder()->addCustomization(m, customization);
}