#pragma once

#include <list>

#include "FloorOrder.h"

class OrderAdapter : public FloorOrder {

public:
	OrderAdapter(const std::vector<std::string>& details) : FloorOrder(details){}

	~OrderAdapter() override;

	RestaurantOrder* PlaceOrder();

private:
	RestaurantOrder* restaurantOrder;
};

