#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
    private:
        std::string name;
        std::string description;
        bool vegetarian;
        double price;
    public:
        MenuItem(std::string name, std::string description, bool vegetarian, double price);
        std::string getName();
        std::string getDescription();
        double getPrice();
        bool isVegetarian();
        void print();
};

#endif // MENUITEM_H