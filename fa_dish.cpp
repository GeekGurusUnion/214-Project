#include <iostream>
#include "fa_dish.h"

void fa_dish::addComponent(const std::string &component) {
    components.push_back(component);
}

void fa_dish::removeComponent(const std::string &component) {

    std::string ingredientToRemove = component.substr(2);

    auto it = std::find(components.begin(), components.end(), ingredientToRemove);
    if (it != components.end()) {
        // Calculate the index
        auto index = std::distance(components.begin(), it);
        //std::cout<<"Found!";
        // Remove the element at the found index
        this->components.erase(components.begin() + index);
    } else {
        //std::cout << "Item not found" << std::endl;
    }

}
