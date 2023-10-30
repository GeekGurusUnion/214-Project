#include "Order.h"

void Order::addItem(MenuItem* item) {
    if (inMenu(item)) {
        item++;
        return;
    }
    items.push(item);
}

bool Order::inMenu(MenuItem* item) {
    std::stack<MenuItem*> temp = std::stack<MenuItem*>();
    bool found = false;
    while (!items.empty()) {
        if (items.top()->getName() == item->getName()) {
            found = true;
        }
        temp.push(items.top());
        items.pop();
    }
    while (!temp.empty()) {
        items.push(temp.top());
        temp.pop();
    }
    return found;
}

void Order::setStatus(bool status) {
    this->status = status;
}

void Order::removeItem(std::string name) {
    std::stack<MenuItem*> temp = std::stack<MenuItem*>();
    while (!items.empty()) {
        if (items.top()->getName() != name) {
            temp.push(items.top());
        }
        items.pop();
    }
    while (!temp.empty()) {
        items.push(temp.top());
        temp.pop();
    }
}