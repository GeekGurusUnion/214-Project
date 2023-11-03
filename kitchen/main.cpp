// main.cpp
#include "ad_OrderAdapter.h"
#include "si_headChef.h"
#include <iostream>

int main() {

    ad_OrderAdapter floorOrder({"Burger", "NoBacon", "ExtraCheese"});
    fa_dish *finalDish = floorOrder.PlaceOrder();

    ad_OrderAdapter otherOrder({"BBQChickenPizza", "ExtraCheese", "noCheese"});
    fa_dish *otherdish = otherOrder.PlaceOrder();


    if (finalDish) {
        std::cout << finalDish->getDescription() << std::endl;
        std::cout << otherdish->getDescription() << std::endl;
        delete finalDish;
        delete otherdish;
    } else {
        std::cout << "Order could not be prepared." << std::endl;
    }

    return 0;
}
