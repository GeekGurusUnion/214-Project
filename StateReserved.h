#ifndef STATE_RESERVED_H_
#define STATE_RESERVED_H_
#include "State.h"
#include <iostream> 

class ReservedState : public State {
public:
    void reserve() {
        std::cout << "Table is already reserved." << std::endl;
    }

    void occupy() {
        std::cout << "Table is reserved and cannot be occupied." << std::endl;
    }

    void empty() {
        std::cout << "Table is now empty." << std::endl;
    }
};

#endif  // STATE_RESERVED_H_