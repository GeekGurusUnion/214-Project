#ifndef STATE_H_
#define STATE_H_

// State (State) [interface]

#include <iostream> 
class RestaurantTable;  // Forward declaration of RestaurantTable       //Not sure if this is needed

class State {
    public:
        virtual void reserve() = 0;
        virtual void occupy() = 0;
        virtual void empty() = 0;
        virtual ~State() {};
};

#endif  // STATE_H_