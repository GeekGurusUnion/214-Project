#pragma once
#include <vector>
#include <string>

class FloorOrder {
private:
    std::vector<std::string> orderDetails;

public:
    FloorOrder(const std::vector<std::string>& details) : orderDetails(details) {}

    std::vector<std::string> getDetails() const {
        return orderDetails;
    }
};

class KitchenOrder {
private:
    std::string item;
    std::vector<std::string> customizations;

public:
    KitchenOrder(const std::string& item, const std::vector<std::string>& customizations)
            : item(item), customizations(customizations) {}

    std::string getItem() const {
        return item;
    }

    std::vector<std::string> getCustomizations() const {
        return customizations;
    }
};
