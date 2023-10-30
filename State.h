#ifndef STATE_H_
#define STATE_H_
#include <iostream> 
class RestaurantTable;  // Forward declaration of RestaurantTable       //Not sure if this is needed

class State {
    protected:
        RestaurantTable *table;      // Not sure if this is needed
    public:
        void set_Table(RestaurantTable *table);
        virtual void reserve() = 0;
        virtual void occupy() = 0;
        virtual void empty() = 0;
        virtual ~State() {};
};

#endif  // STATE_H_