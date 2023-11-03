/**
 * @file ingredient_handler.h
 * @brief Defines classes for handling ingredient customizations in a restaurant system.
 *
 * This file is part of a restaurant system and uses the Chain of Command pattern to handle
 * ingredient customizations in an order.
 */

#pragma once

#include "ca_handler.h"
#include "fa_burger.h"

/**
 * @class ingredientHandler
 * @brief Abstract base class for handling ingredient customizations.
 *
 * This class is part of the chain of command pattern which delegates the customization handling
 * to the appropriate handler in the chain.
 */
class ingredientHandler : public ca_handler {
protected:
    std::string ingredient; ///< The ingredient to be handled.

public:
    /**
     * @brief Constructor that initializes the ingredient to be handled.
     * @param ingredient The ingredient to be handled.
     */
    ingredientHandler(const std::string &ingredient) : ingredient(ingredient) {}

    /**
     * @brief Virtual destructor.
     */
    virtual ~ingredientHandler() {}

    /**
     * @brief Checks if the handler can handle the given customization.
     * @param customization The customization to be checked.
     * @return True if the handler can handle the customization, false otherwise.
     */
    virtual bool canHandle(const std::string &customization) = 0;

    /**
     * @brief Handles the given customization.
     * @param d Pointer to the dish being customized.
     * @param customization The customization to be handled.
     */
    virtual void handle(fa_dish *d, const std::string &customization) = 0;
};

/**
 * @class AddingredientHandler
 * @brief Handler class for adding ingredients.
 *
 * This class is responsible for handling requests to add extra ingredients to a dish.
 */
class AddingredientHandler : public ingredientHandler {
public:
    /**
     * @brief Constructor that initializes the ingredient to be added.
     * @param ingredient The ingredient to be added.
     */
    AddingredientHandler(const std::string &ingredient) : ingredientHandler(ingredient) {}

    /**
     * @brief Checks if the handler can handle the given customization.
     * @param customization The customization to be checked.
     * @return True if the customization is to add the ingredient, false otherwise.
     */
    bool canHandle(const std::string &customization) override {
        return customization == "Extra" + ingredient;
    }

    /**
     * @brief Handles the request to add the ingredient.
     * @param d Pointer to the dish being customized.
     * @param customization The customization to be handled.
     */
    void handle(fa_dish *d, const std::string &customization) override {
        if (canHandle(customization)) {
            d->addComponent(customization);
        }
        if (nextHandler) nextHandler->handle(d, customization);
    }
};

/**
 * @class RemoveingredientHandler
 * @brief Handler class for removing ingredients.
 *
 * This class is responsible for handling requests to remove certain ingredients from a dish.
 */
class RemoveingredientHandler : public ingredientHandler {
public:
    /**
     * @brief Constructor that initializes the ingredient to be removed.
     * @param ingredient The ingredient to be removed.
     */
    RemoveingredientHandler(const std::string &ingredient) : ingredientHandler(ingredient) {}

    /**
     * @brief Checks if the handler can handle the given customization.
     * @param customization The customization to be checked.
     * @return True if the customization is to remove the ingredient, false otherwise.
     */
    bool canHandle(const std::string &customization) override {
        return customization == "No" + ingredient;
    }

    /**
     * @brief Handles the request to remove the ingredient.
     * @param d Pointer to the dish being customized.
     * @param customization The customization to be handled.
     */
    void handle(fa_dish *d, const std::string &customization) override {
        if (canHandle(customization)) {
            d->removeComponent(customization);
        }
        if (nextHandler) nextHandler->handle(d, customization);
    }
};
