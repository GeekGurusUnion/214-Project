#include "MenuItem.h"

MenuItem::MenuItem(std::string name, bool vegetarian, double price) {
    this->name = name;
    this->vegetarian = vegetarian;
    this->price = price;
}

std::string MenuItem::getName() {
    return name;
}

double MenuItem::getPrice() {
    return price;
}

bool MenuItem::isVegetarian() {
    return vegetarian;
}

void MenuItem::operator++(int) {
    quantity++;
}
