/**
 * @file ad_OrderAdapter.h
 * @brief Defines the OrderAdapter class which adapts a floor order to a restaurant order.
 */

#pragma once
#include "ad_FloorOrder.h"

class ad_OrderAdapter : public ad_FloorOrder {
private:
    ad_RestaurantOrder *restaurantOrder; ///< Pointer to an ad_RestaurantOrder instance.

public:
    /**
     * @brief Constructs an OrderAdapter instance with the given order details.
     * @param details Vector of strings containing order details.
     */
    ad_OrderAdapter(const std::vector<std::string> &details) : ad_FloorOrder(details) {}

    /**
     * @brief Destructor for ad_OrderAdapter.
     */
    ~ad_OrderAdapter() override;

    /**
     * @brief Places an order and returns the prepared dish.
     * @return A pointer to the prepared dish object.
     */
    fa_dish *PlaceOrder() override;
};
