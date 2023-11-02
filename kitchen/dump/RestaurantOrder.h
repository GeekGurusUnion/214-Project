#pragma once

#include <vector>
#include <string>

class RestaurantOrder
{

public:
	RestaurantOrder(const std::string &item, const std::vector<std::string> &customizations)
		: item(item), customizations(customizations) {}

	~RestaurantOrder();

	std::string getItem() const;

	std::vector<std::string> getCustomizations() const;

private:
	std::string item;
	std::vector<std::string> customizations;
};
