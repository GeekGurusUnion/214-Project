#include "RestaurantTable.h"
#include "Command.h"

RestaurantTable::RestaurantTable(int i) {
    this->tableNumber = i;
    this->currentState->setTable(this);
}

RestaurantTable::~RestaurantTable() {
    delete currentState;
}

void RestaurantTable::TransitionTo(State *state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->currentState != nullptr)
        delete this->currentState;
    this->currentState = state;
}

void RestaurantTable::setState(State* state) {
    currentState = state;
}

State* RestaurantTable::getState() {
    return this->currentState;
}

void RestaurantTable::occupy() {
    currentState->occupy();
}

void RestaurantTable::empty() {
    currentState->empty();
}

Waiter* RestaurantTable::getWaiter() const {
    return waiter;
}

void RestaurantTable::setWaiter(Waiter* waiter) {
    this->waiter = waiter;
}

void RestaurantTable::confirmOrder() {
    this->cO->execute(this, nullptr);
}

void RestaurantTable::cleanTable() {
    this->cT->execute(this, nullptr);
}

void RestaurantTable::addToOrder(MenuItem* item) {
    this->tO->execute(this, item);
}

Order* RestaurantTable::getOrder() const {
    return this->order;
}

bool RestaurantTable::isAvailable() const {
    return currentState->isOccupied();
}