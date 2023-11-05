#include "fa_dish.h"

void fa_dish::addComponent(const std::string &component) {
    components.push_back(component);
}

void fa_dish::removeComponent(const std::string &component) {
    components.erase(std::remove(components.begin(), components.end(), component), components.end());
}
