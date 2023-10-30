#pragma once

#include <vector>
#include <string>

class RestaurantOrder
{

public:
	RestaurantOrder(const std::string &item, const std::vector<std::string> &customizations)
		: item(item), customizations(customizations) {}

	void PrepareOrder();

	std::string getItem() const;
	std::vector<std::string> getCustomizations() const;

	// void UpdateOrder(std::vector<std::string> contains, std::vector<std::string> customizations);

private:
	std::string item;
	std::vector<std::string> customizations;
};
