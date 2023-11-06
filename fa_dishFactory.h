/**
 * @file fa_dishFactory.h
 * @brief Defines factories for creating different types of dishes in a restaurant system.
 *
 * These classes implement the Factory Method design pattern to create instances of different types of dishes.
 */

#pragma once

#include "fa_dish.h"
#include "ad_RestaurantOrder.h"

/**
 * @class fa_dishFactory
 * @brief Abstract class representing a generic factory for creating dishes.
 *
 * This class defines the interface for creating different types of dishes based on a given order.
 */
class fa_dishFactory {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~fa_dishFactory() {}

    /**
     * @brief Pure virtual function to create a dish based on a given order.
     *
     * This function is intended to be overridden by derived classes to instantiate
     * the appropriate type of dish as per the given order.
     *
     * @param order An instance of ad_RestaurantOrder containing details of the order.
     * @return A pointer to an instance of fa_dish representing the created dish.
     */
    virtual fa_dish *createDish(const ad_RestaurantOrder &order) = 0;
};

/**
 * @class fa_burgerFactory
 * @brief Concrete class representing a factory for creating burger dishes.
 *
 * This class implements the fa_dishFactory interface to create instances of burger dishes.
 */
class fa_burgerFactory : public fa_dishFactory {
public:
    /**
     * @brief Creates a burger dish based on a given order.
     *
     * @param order An instance of ad_RestaurantOrder containing details of the order.
     * @return A pointer to an instance of fa_dish representing the created burger dish.
     */
    fa_dish *createDish(const ad_RestaurantOrder &order) override;
};

/**
 * @class fa_pizzaFactory
 * @brief Concrete class representing a factory for creating pizza dishes.
 *
 * This class implements the fa_dishFactory interface to create instances of pizza dishes.
 */
class fa_pizzaFactory : public fa_dishFactory {
public:
    /**
     * @brief Creates a pizza dish based on a given order.
     *
     * @param order An instance of ad_RestaurantOrder containing details of the order.
     * @return A pointer to an instance of fa_dish representing the created pizza dish.
     */
    fa_dish *createDish(const ad_RestaurantOrder &order) override;
};
