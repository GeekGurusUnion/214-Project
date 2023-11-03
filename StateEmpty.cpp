#include "StateEmpty.h"
#include "RestaurantTable.h"

StateEmpty::StateEmpty(RestaurantTable* table) : State(table) {
    stateName = "Empty";
}

void StateEmpty::occupy() {
    std::cout << "Table is now occupied." << std::endl;
    table->setState(new StateOccupied(table));
}

void StateEmpty::empty() {
    std::cout << "Table is already empty." << std::endl;
}

void StateEmpty::serve() {
    std::cout << "Table is empty, cannot serve." << std::endl;
}

std::string StateEmpty::getStateName() {
    return stateName;
}

bool StateEmpty::isOccupied() {
    return false;
}