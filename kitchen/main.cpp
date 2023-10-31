#include "OrderAdapter.h"
#include "headChef.h"
#include <iostream>

int main() {
    
    OrderAdapter* floorOrder = new OrderAdapter({"chickenBurger", "NoMushrooms", "ExtraCheese"});
    RestaurantOrder* restaurantOrder = floorOrder->PlaceOrder();

    headChef* Chef = new headChef();

    Chef->setOrder(restaurantOrder->getItem(), restaurantOrder->getCustomizations());

    MenuItem* menuItem = Chef->prepareItem();
    
    std::cout << menuItem->getDescription() << std::endl;

    floorOrder = new OrderAdapter({"hawaiianPizza", "ExtraGarlic"});
    restaurantOrder = floorOrder->PlaceOrder();

    
    Chef->setOrder(restaurantOrder->getItem(), restaurantOrder->getCustomizations());

    menuItem = Chef->prepareItem();
    
    std::cout << menuItem->getDescription() << std::endl;


    delete Chef;
    delete restaurantOrder;
    delete floorOrder;

    return 0;
}
