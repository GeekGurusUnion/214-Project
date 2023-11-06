#include "StateServe.h"
#include "RestaurantTable.h"

StateServe::StateServe(RestaurantTable* table) : State(table) {
    stateName = "Serving";
}

void StateServe::occupy() {
    std::cout << "Table is already occupied." << std::endl;
}

void StateServe::empty() {
    std::cout << "Table is now empty." << std::endl;
    table->setState(new StateEmpty(table));
}

void StateServe::serve() {
    std::cout << "Table is already serving food." << std::endl;
}

std::string StateServe::getStateName() {
    return stateName;
}

bool StateServe::isOccupied() {
    return true;
}