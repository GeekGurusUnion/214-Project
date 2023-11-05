#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"

// * a linked list //
class Order {
    private:
        MenuItem* head = nullptr;
        bool status = false;
    public:
        void addItem(MenuItem* item);
        void setStatus(bool status);
        void removeItem(std::string name);
};

#endif // ORDER_H
