#pragma once
#include "dish.h"
#include <vector>
#include <algorithm>

class burger : public dish {
private:
    std::vector<std::string> components;

public:
    burger(const std::vector<std::string>& initialComponents)
            : components(initialComponents) {}

    void addComponent(const std::string& component) {
        components.push_back(component);
    }

    void removeComponent(const std::string& component) {
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
    }

    std::string getDescription() const override {
        std::string description = "Burger with: ";
        for (const auto& component : components) {
            description += component + ", ";
        }
        return description.substr(0, description.length() - 2);
    }
};
