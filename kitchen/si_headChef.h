/**
 * @file si_headChef.h
 * @brief Defines the singleton class si_headChef representing the head chef managing the kitchen.
 *
 * The si_headChef class is responsible for handling restaurant orders and preparing dishes.
 */

#pragma once
#include "fa_dishFactory.h"
#include "ca_handler.h"
#include "ca_ingredientHandler.h"

class ad_RestaurantOrder;

/**
 * @class si_headChef
 * @brief Singleton class representing the head chef that manages the kitchen.
 *
 * This class is responsible for handling restaurant orders, creating handler chains, and preparing dishes.
 * It follows the singleton pattern ensuring there is only one instance of head chef.
 */
class si_headChef {
private:
    ca_handler* startOfChain; ///< Pointer to the start of the handler chain.
    static si_headChef* instance; ///< Static pointer to the single instance of si_headChef.

    /**
     * @brief Private constructor to prevent instantiation.
     */
    si_headChef();

    /**
     * @brief Private copy constructor to prevent copy instantiation.
     */
    si_headChef(const si_headChef& hChef) = delete;

    /**
     * @brief Private copy assignment operator to prevent assignment.
     */
    si_headChef& operator=(const si_headChef& hChef) = delete;

public:
    /**
     * @brief Destructor.
     */
    ~si_headChef();

    /**
     * @brief Deletes the single instance of si_headChef.
     */
    static void destroyInstance();

    /**
     * @brief Gets the single instance of si_headChef.
     *
     * @return Pointer to the single instance of si_headChef.
     */
    static si_headChef* getInstance();

    /**
     * @brief Creates and initializes the handler chain for customizations.
     *
     * @return Pointer to the start of the handler chain.
     */
    ca_handler* createHandlerChain();

    /**
     * @brief Prepares a dish based on the given restaurant order.
     *
     * @param order The restaurant order containing details of the dish to be prepared.
     * @return Pointer to the prepared dish.
     */
    fa_dish* prepareDish(const ad_RestaurantOrder& order);

    /**
     * @brief Selects the appropriate burger factory based on the given item.
     *
     * @param item The type of burger to be prepared.
     * @return Pointer to the selected burger factory.
     */
    fa_dishFactory *selectBurgerFactory(const std::string &item);

    /**
     * @brief Selects the appropriate pizza factory based on the given item.
     *
     * @param item The type of pizza to be prepared.
     * @return Pointer to the selected pizza factory.
     */
    fa_dishFactory *selectPizzaFactory(const std::string &item);
};
