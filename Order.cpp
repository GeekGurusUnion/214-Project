#include "Order.h"

Order::Order(RestaurantTable* table) {
    this->table = table;
}

Order::~Order() {
    items.clear();
}

void Order::addItem(MenuItem* item) {
    items.push_back(item);
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

void Order::addCustomization(std::string name, std::string customization) {
    for (auto& i : items) {
        if (i->getName() == name) {
            i->addCustomization(customization);
            std::cout << "Customization successfully added." << std::endl;
        }
    }
}

// * testing
int Order::getOrderSize() {
    return this->items.size();
}