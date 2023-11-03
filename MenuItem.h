#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
    private:
        std::string name;
        double price;
    public:
        MenuItem(std::string name, double price);
        ~MenuItem();
        std::string getName();
        double getPrice();
};

#endif // MENUITEM_H