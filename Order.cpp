#include "Order.h"

Order::Order(RestaurantTable* table) {
    this->table = table;
}

Order::~Order() {
    while (!items.empty()) {
        delete items.back();
        items.pop_back();
    }
    while (!dishes.empty()) {
        delete dishes.back();
        dishes.pop_back();
    }
    items.clear();
    dishes.clear();
}

void Order::addItem(MenuItem* item) {
    MenuItem* mi = new MenuItem(*item);
    items.push_back(mi);
}

void Order::setStatus(bool status) {
    this->status = status;
}

void Order::removeItem(std::string name) {
    std::vector<MenuItem*> temp;
    for (auto& i : items) {
        if (i->getName() != name) {
            temp.push_back(i);
        }
    }
    items = temp;
}

RestaurantTable* Order::getTable() {
    return table;
}

std::vector<MenuItem*> Order::getItems() {
    return items;
}

void Order::addDish(fa_dish* dish) {
    dishes.push_back(dish);
}

void Order::addCustomization(std::string name, std::string customization) {
    for (auto& i : items) {
        if (i->getName() == name) {
            if (i->containsCustomization(customization)) 
                continue;
            i->addCustomization(customization);
            return;
        }
    }
}

// * testing
int Order::getOrderSize() {
    return this->items.size();
}

void Order::printOrder() {
    // loop through dish
    std::cout << "Printing order" << std::endl;
    for (auto& d : dishes) {
        std::cout << d->getDescription() << std::endl;
    }
}
