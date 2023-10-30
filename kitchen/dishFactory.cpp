#include "dishFactory.h"
#include "burger.h"

dish* burgerFactory::createDish(const KitchenOrder& order) {
    std::vector<std::string> basicComponents = {"buns", "lettuce", "patty", "mayo", "cheese", "bacon"};
    return new burger(basicComponents);
}
