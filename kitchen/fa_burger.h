/**
 * @file fa_burger.h
 * @brief Defines the abstract product and concrete products for burgers in a restaurant system.
 *
 * These classes are used by factory methods to create instances of different types of burgers.
 */

#pragma once

#include <list>
#include "fa_dish.h"

/**
 * @class fa_burger
 * @brief Abstract product class representing a generic burger dish.
 *
 * This class provides a base implementation for different types of burgers.
 */
class fa_burger : public fa_dish {
public:
    /**
     * @brief Constructor that initializes the burger with initial components.
     * @param initialComponents A vector of strings representing the initial components of the burger.
     */
    fa_burger(const std::vector<std::string> &initialComponents) { components = initialComponents; };

    /**
     * @brief Gets the description of the burger.
     * @return A string representing the description of the burger and its components.
     */
    std::string getDescription() const override {
        std::string description = "Burger with: ";
        for (const auto &component: components) {
            description += component + ", ";
        }
        return description.substr(0, description.length() - 2);
    }
};

/**
 * @class DoubleBurger
 * @brief Concrete product class representing a double burger dish.
 *
 * This class implements a burger with two beef patties as its main ingredients.
 */
class DoubleBurger : public fa_burger {
public:
    /**
     * @brief Constructor that initializes the double burger with initial components.
     * @param initialComponents A vector of strings representing the initial components of the double burger.
     */
    DoubleBurger(const std::vector<std::string> &initialComponents) : fa_burger(initialComponents) {
        std::list<std::string> ingredients = {"Beef Patty", "Beef Patty"};
        for (std::string a: ingredients) {
            addComponent(a);
        }
    }
};

/**
 * @class BeefBurger
 * @brief Concrete product class representing a beef burger dish.
 *
 * This class implements a burger with a beef patty as its main ingredient.
 */
class BeefBurger : public fa_burger {
public:
    /**
     * @brief Constructor that initializes the beef burger with initial components.
     * @param initialComponents A vector of strings representing the initial components of the beef burger.
     */
    BeefBurger(const std::vector<std::string> &initialComponents) : fa_burger(initialComponents) {
        std::list<std::string> ingredients = {"Beef Patty"};
        for (std::string a: ingredients) {
            addComponent(a);
        }
    }
};

/**
 * @class ChickenBurger
 * @brief Concrete product class representing a chicken burger dish.
 *
 * This class implements a burger with a chicken breast and pickle as its main ingredients.
 */
class ChickenBurger : public fa_burger {
public:
    /**
     * @brief Constructor that initializes the chicken burger with initial components.
     * @param initialComponents A vector of strings representing the initial components of the chicken burger.
     */
    ChickenBurger(const std::vector<std::string> &initialComponents) : fa_burger(initialComponents) {
        std::list<std::string> ingredients = {"Chicken Breast", "Pickle"};
        for (std::string a: ingredients) {
            addComponent(a);
        }
    }
};
