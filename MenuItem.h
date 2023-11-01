#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
    private:
        std::string name;
        double price;
        int quantity = 0;
    public:
        MenuItem(std::string name, double price);
        std::string getName();
        double getPrice();
        bool isVegetarian();
        void operator++(int);
};

#endif // MENUITEM_H