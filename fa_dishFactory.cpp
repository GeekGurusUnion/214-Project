#include "fa_dishFactory.h"
#include "fa_burger.h"
#include "fa_Pizza.h"

fa_dish *fa_burgerFactory::createDish(const ad_RestaurantOrder &order) {
    std::vector<std::string> basicComponents = {"buns", "lettuce", "mayo", "Cheese", "Bacon"};
    if (order.getItem() == "DoubleBurger") {
        return new DoubleBurger(basicComponents);
    } else if (order.getItem() == "BeefBurger") {
        return new BeefBurger(basicComponents);
    } else if (order.getItem() == "ChickenBurger") {
        return new ChickenBurger(basicComponents);
    } else {
        return new fa_burger(basicComponents);
    }
}

fa_dish *fa_pizzaFactory::createDish(const ad_RestaurantOrder &order) {
    std::vector<std::string> basicComponents = {"Base", "Tomato Sauce", "Mozzarella"};
    if (order.getItem() == "PepperoniPizza") {
        return new PepperoniPizza(basicComponents);
    } else if (order.getItem() == "BBQChickenPizza") {
        return new BBQChickenPizza(basicComponents);
    } else if (order.getItem() == "HawaiianPizza") {
        return new HawaiianPizza(basicComponents);
    } else {
        return new fa_Pizza(basicComponents);
    }
}
