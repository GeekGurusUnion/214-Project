#pragma once

#include <list>

#include "FloorOrder.h"
// #include "RestaurantOrder.h"

class FloorOrder;

class OrderAdapter : public FloorOrder {

public:
	OrderAdapter(const std::vector<std::string>& details) : FloorOrder(details){}
	RestaurantOrder* restaurantOrder;

	RestaurantOrder* PlaceOrder();

	// void TranslateOrder();

	// void changeOrder(std::list<std::string> raw);
};

