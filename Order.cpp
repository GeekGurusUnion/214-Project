#include "Order.h"

Order::Order(RestaurantTable* table) {
    this->table = table;
}

void Order::addItem(MenuItem* item) {
    if (inMenu(item)) {
        item++;
        return;
    }
    items.push_back(item);
}

bool Order::inMenu(MenuItem* item) {
    bool found = false;
    for (auto& i : items) {
        if (i->getName() == item->getName()) {
            found = true;
            break;
        }
    }
    return found;
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