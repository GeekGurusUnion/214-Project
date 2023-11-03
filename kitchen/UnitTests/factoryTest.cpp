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