#ifndef RESTAURANT_TABLE_H_
#define RESTAURANT_TABLE_H_
#include "State.h"
#include <iostream> 

class RestaurantTable : public State {
private:
    State* currentState;

public:
    RestaurantTable();
    RestaurantTable(State *state) : currentState(nullptr) {};
    ~RestaurantTable() {};
    void TransitionTo(State *state) {};
    void setState(State* state) {};
    void reserve() {};
    void occupy() {};
    void empty() {};
};

#endif  // RESTAURANT_TABLE_H_