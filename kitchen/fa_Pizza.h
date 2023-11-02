/**
 * @file fa_Pizza.h
 * @brief Defines the abstract and concrete classes representing different types of pizzas.
 *
 * This file includes the fa_Pizza abstract class and its derived concrete pizza classes.
 */

#pragma once

#include <list>
#include "fa_dish.h"

/**
 * @class fa_Pizza
 * @brief Abstract class representing a generic pizza dish.
 *
 * This class defines the basic characteristics of a pizza and is derived from the fa_dish class.
 */
class fa_Pizza : public fa_dish {
public:
    /**
     * @brief Constructor initializing the pizza with its initial components.
     *
     * @param initialComponents A vector of strings representing the initial components of the pizza.
     */
    fa_Pizza(const std::vector<std::string> &initialComponents) {
        components = initialComponents;
    };

    /**
     * @brief Gets a description of the pizza.
     *
     * @return A string representing the description of the pizza along with its components.
     */
    std::string getDescription() const override {
        std::string description = "Pizza with: ";
        for (const auto &component: components) {
            description += component + ", ";
        }
        return description.substr(0, description.length() - 2);
    }
};

/**
 * @class PepperoniPizza
 * @brief Concrete class representing a Pepperoni Pizza.
 *
 * This class is a specific type of pizza with certain default ingredients.
 */
class PepperoniPizza : public fa_Pizza {
public:
    /**
     * @brief Constructor initializing a Pepperoni Pizza with its components.
     *
     * @param initialComponents A vector of strings representing the initial components of the pizza.
     */
    PepperoniPizza(const std::vector<std::string> &initialComponents) : fa_Pizza(initialComponents) {
        std::list<std::string> ingredients = {"Pepperoni", "Garlic"};
        for (std::string a: ingredients) {
            addComponent(a);
        }
    }
};

/**
 * @class BBQChickenPizza
 * @brief Concrete class representing a BBQ Chicken Pizza.
 *
 * This class is a specific type of pizza with certain default ingredients.
 */
class BBQChickenPizza : public fa_Pizza {
public:
    /**
     * @brief Constructor initializing a BBQ Chicken Pizza with its components.
     *
     * @param initialComponents A vector of strings representing the initial components of the pizza.
     */
    BBQChickenPizza(const std::vector<std::string> &initialComponents) : fa_Pizza(initialComponents) {
        std::list<std::string> ingredients = {"BBQChicken", "Bacon", "Green Pepper"};
        for (std::string a: ingredients) {
            addComponent(a);
        }
    }
};

/**
 * @class HawaiianPizza
 * @brief Concrete class representing a Hawaiian Pizza.
 *
 * This class is a specific type of pizza with certain default ingredients.
 */
class HawaiianPizza : public fa_Pizza {
public:
    /**
     * @brief Constructor initializing a Hawaiian Pizza with its components.
     *
     * @param initialComponents A vector of strings representing the initial components of the pizza.
     */
    HawaiianPizza(const std::vector<std::string> &initialComponents) : fa_Pizza(initialComponents) {
        std::list<std::string> ingredients = {"Pineapple", "Ham"};
        for (std::string a: ingredients) {
            addComponent(a);
        }
    }
};
