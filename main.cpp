// main.cpp
#include "kitchen/ad_OrderAdapter.h"
#include "kitchen/si_headChef.h"
#include <iostream>

int main() {
    ad_OrderAdapter floorOrder({"Burger", "NoOnion", "ExtraCheese"});
    fa_dish* finalDish = floorOrder.PlaceOrder();

    if(finalDish) {
        std::cout << finalDish->getDescription() << std::endl;
        delete finalDish;
    } else {
        std::cout << "Order could not be prepared." << std::endl;
    }

    return 0;
}
