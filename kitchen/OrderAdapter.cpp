#include "OrderAdapter.h"

RestaurantOrder* OrderAdapter::PlaceOrder()
{
	auto details = this->getDetails();
	std::string item = details[0];
	std::vector<std::string> customizations(details.begin() + 1, details.end());
	this->restaurantOrder = new RestaurantOrder(item, customizations);
	this->restaurantOrder->PrepareOrder();

	return restaurantOrder;
}

// void OrderAdapter::TranslateOrder() {
// 	// TODO - implement OrderAdapter::TranslateOrder
// 	throw "Not yet implemented";
// }

// void OrderAdapter::changeOrder(list<string> raw) {
// 	// TODO - implement OrderAdapter::changeOrder
// 	throw "Not yet implemented";
// }
