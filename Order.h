#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include "RestaurantTable.h"
#include <vector>

class Order {
    private:
        std::vector<MenuItem*> items = std::vector<MenuItem*>();
        RestaurantTable* table;
        bool status = false;
    public:
        Order(RestaurantTable* table);
        ~Order();
        void addItem(MenuItem* item);
        void setStatus(bool status);
        void removeItem(std::string name);
        RestaurantTable* getTable();
        int getOrderSize(); // * testing
};

#endif // ORDER_H
