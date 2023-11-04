#include "MenuItem.h"

MenuItem::MenuItem(std::string name, double price) {
    this->name = name;
    this->price = price;
}

MenuItem::~MenuItem() {}

std::string MenuItem::getName() {
    return name;
}

double MenuItem::getPrice() {
    return price;
}

void MenuItem::addCustomization(std::string customization) {
    customizations.push_back(customization);
    std::cout << "Added customizations" << std::endl;
}

bool MenuItem::containsCustomization(std::string customization) {
    for (auto& i : customizations) {
        if (i == customization) {
            return true;
        }
    }
    return false;
}
