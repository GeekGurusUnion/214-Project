#include "RestaurantTable.h"
#include "Command.h"
#include "Waiter.h"

RestaurantTable::RestaurantTable(int i) : tableNumber(i) {
    this->currentState->setTable(this);
    this->order = new Order(this);
    this->observer = new TableObserver(this);
}

RestaurantTable::~RestaurantTable() {
    // if (currentState != NULL) {
    //     delete currentState;
    // }
    if (order != NULL)
        delete order;
    // if (waiter != NULL) {
    //     delete waiter; 
    // }
    if (observer != NULL)
        delete observer;
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

void RestaurantTable::empty() {
    currentState->empty();
    observer->update("empty", false);
}

Waiter* RestaurantTable::getWaiter() const {
    return waiter;
}

void RestaurantTable::setWaiter(Waiter* waiter) {
    this->waiter = waiter;
    // delete this->observer;
    this->observer = new TableObserver(this);
}

void RestaurantTable::notifyWaiter(std::string action, bool isItem) {
    this->observer->update(action, isItem);
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
    notifyWaiter(item, true);       //Always passing in true
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