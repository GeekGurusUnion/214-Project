#pragma once

#include <vector>
#include <string>

#include "RestaurantOrder.h"

class FloorOrder {
public:
    FloorOrder(const std::vector<std::string>& details) : orderDetails(details) {}

    virtual ~FloorOrder();

	void PlaceOrder();

	std::vector<std::string> getDetails() const;

protected:
    std::vector<std::string> orderDetails;
};

