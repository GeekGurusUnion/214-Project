/**
 * @file fa_emptyDish.h
 * @brief Defines an enpty dish.
 *
 * This file includes the fa_emptyDish class.
 */

#pragma once

#include <list>
#include "fa_dish.h"

/**
 * @class fa_emptyDish
 * @brief Class representing an empty dish.
 *
 * This class defines the basic characteristics of an empty dish.
 */
class fa_emptyDish : public fa_dish {
public:
    /**
     * @brief Constructor initializing the dish with no initial components.
     *
     * @param initialComponents A vector of strings representing the initial components of the pizza.
     */
    fa_emptyDish(const std::vector<std::string> &initialComponents) {
        components = {""};
    };

    /**
     * @brief Gets a description of the dish.
     *
     * @return A string representing the description of the dish.
     */
    std::string getDescription() const override {
        std::string description = "Empty dish.";
        return description;
    }
};
