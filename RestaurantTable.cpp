#include "RestaurantTable.h"
#include "Command.h"

RestaurantTable::RestaurantTable(int i) : tableNumber(i) {
    this->currentState->setTable(this);
    this->order = new Order(this);
    this->observer = new TableObserver(this);
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
    observer->update("empty", false);
}

Waiter* RestaurantTable::getWaiter() const {
    return waiter;
}

void RestaurantTable::setWaiter(Waiter* waiter) {
    this->waiter = waiter;
    this->observer = new TableObserver(this);
}

void RestaurantTable::notifyWaiter(std::string action, bool isItem) {
    observer->update(action, isItem);
}

void RestaurantTable::confirmOrder() {
    notifyWaiter("confirm", false);
}

void RestaurantTable::welcomeWaiter() {
    notifyWaiter("welcome", false);
}

void RestaurantTable::cleanTable() {
    notifyWaiter("clean", false);
}

void RestaurantTable::addToOrder(std::string item) {
    notifyWaiter(item, true);
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