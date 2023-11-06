#include "RestaurantTable.h"
#include "Command.h"
#include "Waiter.h"

RestaurantTable::RestaurantTable(int i, int t) : tableNumber(i), tableSize(t) {
    this->currentState = new StateEmpty(this); 
    this->order = new Order(this);
}

RestaurantTable::~RestaurantTable() {
    if (currentState != nullptr) {
        delete this->currentState;
    }
    delete this->order;
}

void RestaurantTable::setState(State* state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->currentState != nullptr)
        delete this->currentState;
    this->currentState = state;
}

State* RestaurantTable::getState() {
    return this->currentState;
}

void RestaurantTable::occupy() {
    currentState->occupy();
}

Waiter* RestaurantTable::getWaiter() const {
    return waiter;
}

void RestaurantTable::setWaiter(Waiter* waiter) {
    this->waiter = waiter;
}

Order* RestaurantTable::getOrder() const {
    if (this->order != nullptr) {
        return this->order;
    }
    else {
        std::cout << "Error: Order is null." << std::endl;
        return nullptr;
    }
}

bool RestaurantTable::isAvailable() const {
    return !currentState->isOccupied();
}

int RestaurantTable::getTableNumber() const {
    return this->tableNumber;
}

float RestaurantTable::calculateBill() {
    // iterate through order and add up prices
    float total = 0;
    for (auto& item : order->getItems()) {
        total += item->getPrice();
    }
    return total;
}

void RestaurantTable::printBill() {
    std::cout << "Table " << tableNumber << " Bill: $" << calculateBill() << std::endl;
}

int RestaurantTable::getTableSize() {
    return this->tableSize;
}

void RestaurantTable::serve() {
    currentState->serve();
}
