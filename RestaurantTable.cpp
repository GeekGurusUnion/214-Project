#include "RestaurantTable.h"\

RestaurantTable::RestaurantTable() {
        currentState = new StateEmpty();
    }

RestaurantTable::RestaurantTable(State *state) : currentState(nullptr) {
    this->TransitionTo(state);
}
~RestaurantTable() {
    delete currentState;
}

void TransitionTo(State *state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->currentState != nullptr)
        delete this->currentState;
    this->currentState = state;
    this->currentState->set_context(this);
}

void setState(State* state) {
    currentState = state;
}

void reserve() {
    currentState->reserve();
}

void occupy() {
    currentState->occupy();
}

void empty() {
    currentState->empty();
};