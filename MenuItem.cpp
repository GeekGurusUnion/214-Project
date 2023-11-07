#include "MenuItem.h"

MenuItem::MenuItem(std::string name, double price) {
    this->name = name;
    this->price = price;
}

MenuItem::~MenuItem() {}

MenuItem::MenuItem(const MenuItem& other) {
    this->name = other.name;
    this->price = other.price;
    this->customizations = other.customizations;
}

std::string MenuItem::getName() {
    return name;
}

double MenuItem::getPrice() {
    return price;
}

void MenuItem::addCustomization(std::string customization) {
    customizations.push_back(customization);
    // std::cout << "Added customizations" << std::endl;
}

bool MenuItem::containsCustomization(std::string customization) {
    for (auto& i : customizations) {
        if (i == customization) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> MenuItem::getCustomizations() {
    return this->customizations;
}
