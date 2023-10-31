#include "StateOccupied.h"
#include "RestaurantTable.h"

StateOccupied::StateOccupied() : State() {
    stateName = "Occupied";
}

void StateOccupied::occupy() {
    std::cout << "Table is already occupied." << std::endl;
}

void StateOccupied::empty() {
    std::cout << "Table is now empty." << std::endl;
    table->setState(new StateEmpty());
}

void StateOccupied::serve() {
    std::cout << "Table is occupied, serving food." << std::endl;
    table->setState(new StateServe());
}

std::string StateOccupied::getStateName() {
    return stateName;
}

bool StateOccupied::isOccupied() {
    return true;
}