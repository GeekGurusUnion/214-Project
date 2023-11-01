#include "MenuItem.h"

MenuItem::MenuItem(std::string name, double price) {
    this->name = name;
    this->price = price;
}

std::string MenuItem::getName()
{
    return name;
}

double MenuItem::getPrice() {
    return price;
}

void MenuItem::operator++(int) {
    quantity++;
}
