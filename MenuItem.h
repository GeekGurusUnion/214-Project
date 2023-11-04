#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>
#include <iostream>

class MenuItem {
    private:
        std::string name;
        std::vector<std::string> customizations = {};
        double price;
    public:
        MenuItem(std::string name, double price);
        ~MenuItem();
        std::string getName();
        double getPrice();
        void addCustomization(std::string customization);
        bool containsCustomization(std::string customization);
};

#endif // MENUITEM_H