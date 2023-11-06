#include "StateOccupied.h"
#include "RestaurantTable.h"

StateOccupied::StateOccupied(RestaurantTable* table) : State(table) {
    stateName = "Occupied";
}

void StateOccupied::occupy() {
    std::cout << "Table is already occupied." << std::endl;
}

void StateOccupied::empty() {
    std::cout << "Table is now empty." << std::endl;
    table->setState(new StateEmpty(table));
}

void StateOccupied::serve() {
    std::cout << "Table is occupied, serving food." << std::endl;
    table->setState(new StateServe(table));
}

std::string StateOccupied::getStateName() {
    return stateName;
}

bool StateOccupied::isOccupied() {
    return true;
}