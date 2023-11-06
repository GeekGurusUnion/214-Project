<<<<<<< HEAD
#include <stdexcept>
#include "headChefTest.h"

std::string testHeadChef(const std::string &item, const std::vector<std::string> &customizations){
    ad_RestaurantOrder* order = new ad_RestaurantOrder(item, customizations);

    si_headChef* chef = si_headChef::getInstance();

    fa_dish* dish = chef->prepareDish(*order);

    std::string result;

    if (dish != nullptr){
        result = dish->getDescription();
    }else{
        result = "Dish unavailable.";
    }

    delete order;
    delete dish;

    return result;
}

si_headChef* testSingleton(){
    return si_headChef::getInstance();
=======
#include <stdexcept>
#include "headChefTest.h"

std::string testHeadChef(const std::string &item, const std::vector<std::string> &customizations){
    ad_RestaurantOrder* order = new ad_RestaurantOrder(item, customizations);

    si_headChef* chef = si_headChef::getInstance();

    fa_dish* dish = chef->prepareDish(*order);

    std::string result;

    if (dish != nullptr){
        result = dish->getDescription();
    }else{
        result = "Dish unavailable.";
    }

    delete order;
    delete dish;

    return result;
}

si_headChef* testSingleton(){
    return si_headChef::getInstance();
>>>>>>> 7445f2bc56b97a1dd23166483edccaa3f44c8ce9
}