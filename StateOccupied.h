#ifndef STATE_OCCUPIED_H_
#define STATE_OCCUPIED_H_
#include "State.h"
#include <iostream> 
class StateOccupied : public State {
public:
    void reserve() {
        std::cout << "Table is occupied and cannot be reserved." << std::endl;
    }

    void occupy() {
        std::cout << "Table is already occupied." << std::endl;
    }

    void empty() {
        std::cout << "Table is now empty." << std::endl;
    }
};

#endif  // STATE_OCCUPIED_H_