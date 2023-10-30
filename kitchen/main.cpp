#include "OrderAdapter.h"
#include "headChef.h"
#include <iostream>

int main() {
    
    OrderAdapter* floorOrder = new OrderAdapter({"Burger", "NoMushrooms", "ExtraCheese"});
    RestaurantOrder* restaurantOrder = floorOrder->PlaceOrder();

    headChef* Chef = new headChef(restaurantOrder->getItem(), restaurantOrder->getCustomizations());

    MenuItem* menuItem = Chef->prepareItem();
    
    std::cout << menuItem->getDescription() << std::endl;

    delete Chef;
    delete restaurantOrder;
    delete floorOrder;
    return 0;
}
