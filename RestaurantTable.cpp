#include "RestaurantTable.h"
#include "ConfirmOrder.h"
#include "CleanTable.h"
#include "TakeOrder.h"

RestaurantTable::RestaurantTable(int i, Iterator* tableIterator) {
    currentState = new StateEmpty();
    this->cO = new ConfirmOrder(this->waiter);
    this->cT = new CleanTable(this->waiter); 
    this->tO = new TakeOrder(this->waiter);
    this->tableNumber = i;
    tableIterator = createIterator();
}

RestaurantTable::~RestaurantTable() {
    delete currentState;
}

void RestaurantTable::TransitionTo(State *state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->currentState != nullptr)
        delete this->currentState;
    this->currentState = state;
    // this->currentState->setTable(this);
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
};

TableIterator* RestaurantTable::createIterator() {
    return new TableIterator(this);
}