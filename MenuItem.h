#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
    private:
        std::string name;
        bool vegetarian;
        double price;
        int quantity = 0;
    public:
        MenuItem(std::string name, bool vegetarian, double price);
        std::string getName();
        double getPrice();
        bool isVegetarian();
        void operator++(int);
};

#endif // MENUITEM_H