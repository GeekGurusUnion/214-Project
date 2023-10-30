#include "adapter.h"
#include "HeadChef.h"
#include <iostream>

int main() {
    FloorOrder floorOrder({"Burger", "NoOnion", "ExtraCheese"});
    KitchenOrder kitchenOrder = adapter::adapt(floorOrder);
    headChef headChef;
    dish* finalDish = headChef.prepareDish(kitchenOrder);
    std::cout << finalDish->getDescription() << std::endl;
    delete finalDish;
    return 0;
}
