#ifndef STATE_H_
#define STATE_H_

// State (State) [interface]

#include <iostream> 

class RestaurantTable;

class State {
    protected:
        RestaurantTable* table = nullptr;
        std::string stateName;
    public:
        State(RestaurantTable* table);
        virtual ~State();
        void setTable(RestaurantTable* table);
        virtual void serve() = 0;
        virtual void occupy() = 0;
        virtual void empty() = 0;
        virtual std::string getStateName() = 0;
        virtual bool isOccupied() = 0;
};

#include "StateEmpty.h"
#include "StateOccupied.h"
#include "StateServe.h"

#endif  // STATE_H_