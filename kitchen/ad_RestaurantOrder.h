/**
 * @file ad_RestaurantOrder.h
 * @brief Defines the class representing a restaurant order.
 */

#pragma once
#include <vector>
#include <string>

class fa_dish;

class ad_RestaurantOrder {
private:
    std::string item; ///< The main item in the order.
    std::vector<std::string> customizations; ///< Customizations for the order.

public:
    /**
     * @brief Constructs a RestaurantOrder with the given item and customizations.
     * @param item The main item of the order.
     * @param customizations Vector of strings representing the customizations.
     */
    ad_RestaurantOrder(const std::string &item, const std::vector<std::string> &customizations);

    /**
     * @brief Destructor for ad_RestaurantOrder.
     */
    ~ad_RestaurantOrder();

    /**
     * @brief Fetches the item in the order.
     * @return A string representing the item in the order.
     */
    std::string getItem() const;

    /**
     * @brief Fetches the customizations of the order.
     * @return A vector of strings representing the customizations.
     */
    std::vector<std::string> getCustomizations() const;

    /**
     * @brief Prepares the dish according to the order.
     * @return A pointer to the prepared dish object.
     */
    fa_dish *prepare();
};
