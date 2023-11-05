#ifndef RESTAURANT_TABLE_H_
#define RESTAURANT_TABLE_H_
#include "StateEmpty.h"
#include "Table.h"
#include <iostream> 

class RestaurantTable : public Table {
private:
    State* currentState;

public:
    RestaurantTable();
    RestaurantTable(State *state);
    ~RestaurantTable();
    void TransitionTo(State *state);
    void setState(State* state);
    void reserve();
    void occupy();
    void empty();
};

#endif  // RESTAURANT_TABLE_H_