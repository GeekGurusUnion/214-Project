#include "Waiter.h"
#include "WaiterStateAvailable.h"
#include "WaiterStateUnavailable.h"

Waiter::Waiter(std::string name, int totalOrders, FloorColleague *fc) {
    this->name = name;
    this->totalOrders = totalOrders;
    this->setWaiterState(new WaiterStateAvailable());
    this->floorColleague = fc;
}

// TODO: Figure out a way to add to the Order obj stack (build the order)
void Waiter::addItem(RestaurantTable* rt, MenuItem* m) {
    Order* o = getOrder(rt);
    if (o == nullptr) {
        std::cout << "Waiter: No order found for table " << rt << ".\n";
        return;
    }
    o->addItem(m);
}

void Waiter::cleanUp(RestaurantTable* rt) {
    rt->cleanTable();
}

// TODO: Needs to be send to Mediator (Concrete Colleague)
void Waiter::confirmOrder(RestaurantTable* rt) {
    // pass order to mediator
    Order* o = getOrder(rt);
    if (o == nullptr) {
        std::cout << "Waiter: No order found for table " << rt << ".\n";
        return;
    }
    floorColleague->setOrder(o);
    floorColleague->changed();
}

void Waiter::addOrder(RestaurantTable* rt) {
    busyOrders++;
    if (busyOrders > totalOrders) {
        std::cout << "Waiter: Sorry, I can't take any more orders.\n";
        this->setWaiterState(new WaiterStateUnavailable());
        return;
    }
    tables.push_back(rt);
}

void Waiter::setWaiterState(WaiterState* state) {
    this->state = state;
    this->state->setWaiter(this);
}

Order* Waiter::getOrder(RestaurantTable* rt) {
    for (auto& t : tables) {
        if (t == rt) {
            return t->getOrder();
        }
    }
    return nullptr;
}

bool Waiter::isAvailable() {
    if (busyOrders < totalOrders) {
        return true;
    }
    return false;
}

std::string Waiter::getName() const {
    return this->name;
}
