#ifndef STATE_EMPTY_H_
#define STATE_EMPTY_H_
#include "State.h"
#include <iostream> 
class StateEmpty : public State {
public:
    void reserve() {
        std::cout << "Table is now reserved." << std::endl;
    }

    void occupy() {
        std::cout << "Table is now occupied." << std::endl;
    }

    void empty() {
        std::cout << "Table is already empty." << std::endl;
    }
};

#endif  // STATE_EMPTY_H_