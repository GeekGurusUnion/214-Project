#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"

// * a linked list //
class Order {
    private:
        MenuItem* head;
        MenuItem* tail;
        bool status;
    public:
        Order(); // default constructor
        // add any other constructors you need here
        // add any other member functions you need here
};

#endif // ORDER_H
