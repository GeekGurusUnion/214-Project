/**
 * @file ad_FloorOrder.h
 * @brief Defines the interface for representing an order placed on the restaurant floor.
 */

#pragma once
#include <vector>
#include <string>
#include "ad_RestaurantOrder.h"

class ad_FloorOrder {
protected:
    std::vector<std::string> orderDetails; ///< Stores the details of the floor order.

public:
    /**
     * @brief Destructor for ad_FloorOrder.
     */
    virtual ~ad_FloorOrder();

    /**
     * @brief Constructs a floor order with the given details.
     * @param details Vector of strings containing order details.
     */
    ad_FloorOrder(const std::vector<std::string> &details) : orderDetails(details) {}

    /**
     * @brief Pure virtual function to place an order.
     * @return A pointer to a dish object.
     */
    virtual fa_dish* PlaceOrder() = 0;

    /**
     * @brief Fetches the order details.
     * @return A vector of strings representing the order details.
     */
    std::vector<std::string> getDetails() const;
};
