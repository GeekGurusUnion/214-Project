#include "OrderAdapter.h"

OrderAdapter::~OrderAdapter()
{
	if (restaurantOrder != NULL)
	{
		delete restaurantOrder;
	}
}

RestaurantOrder *OrderAdapter::PlaceOrder()
{
	auto details = this->getDetails();
	std::string item = details[0];
	std::vector<std::string> customizations(details.begin() + 1, details.end());
	this->restaurantOrder = new RestaurantOrder(item, customizations);

	return restaurantOrder;
}
