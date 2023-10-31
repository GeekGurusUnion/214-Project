#include "StateServe.h"

StateServe::StateServe() {
    stateName = "Serving";
}

void StateServe::occupy() {
    std::cout << "Table is already occupied." << std::endl;
}

void StateServe::empty() {
    std::cout << "Table is now empty." << std::endl;
    table->setState(new StateEmpty());
}

void StateServe::serve() {
    std::cout << "Table is already serving food." << std::endl;
}

std::string StateServe::getStateName() {
    return stateName;
}