#include "ConfirmOrder.h"
#include "Waiter.h"

ConfirmOrder::ConfirmOrder(Waiter* waiter, FloorColleague* fc) : Command(waiter) {
    floorColleague = fc;
}

void ConfirmOrder::execute(RestaurantTable* rt, MenuItem* m = nullptr) {
    if (rt->getOrder() == nullptr) {
        std::cout << "Waiter: No order found for table " << rt << ".\n";
        return;
    }
    floorColleague->setOrder(rt->getOrder());
    floorColleague->changed();
}