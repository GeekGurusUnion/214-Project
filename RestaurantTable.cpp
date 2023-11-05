#include "RestaurantTable.h"

RestaurantTable::RestaurantTable() {
    currentState = new StateEmpty();
}

RestaurantTable::RestaurantTable(State *state) : currentState(nullptr) {
    this->TransitionTo(state);
}
RestaurantTable::~RestaurantTable() {
    delete currentState;
}

void RestaurantTable::TransitionTo(State *state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->currentState != nullptr)
        delete this->currentState;
    this->currentState = state;
    this->currentState->set_Table(this);
}

void RestaurantTable::setState(State* state) {
    currentState = state;
}

void RestaurantTable::reserve() {
    currentState->reserve();
}

void RestaurantTable::occupy() {
    currentState->occupy();
}

void RestaurantTable::empty() {
    currentState->empty();
};