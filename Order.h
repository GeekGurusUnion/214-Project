#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include <stack>

class Order {
    private:
        std::stack<MenuItem*> items = std::stack<MenuItem*>();
        bool status = false;
        int id = 0;
    public:
        Order(int id);
        void addItem(MenuItem* item);
        bool inMenu(MenuItem* item);
        void setStatus(bool status);
        void removeItem(std::string name);
};

#endif // ORDER_H
