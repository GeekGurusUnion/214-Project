#include <stdexcept>
#include "factoryTest.h"

std::string testPizza(const std::string &item, const std::vector<std::string> &customizations){
    ad_RestaurantOrder* order = new ad_RestaurantOrder(item, customizations);

    fa_pizzaFactory* factory = new fa_pizzaFactory();
    fa_dish* pizza = factory->createDish(*order);

    std::string result = pizza->getDescription();

    delete order;
    delete factory;
    delete pizza;

    return result;
}

std::string testBurger(const std::string &item, const std::vector<std::string> &customizations){
    ad_RestaurantOrder* order = new ad_RestaurantOrder(item, customizations);

    fa_burgerFactory* factory = new fa_burgerFactory();
    fa_dish* burger = factory->createDish(*order);

    std::string result = burger->getDescription();

    delete order;
    delete factory;
    delete burger;

    return result;
}