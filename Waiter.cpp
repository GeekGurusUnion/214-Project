#include "Waiter.h"
#include "WaiterStateAvailable.h"
#include "WaiterStateUnavailable.h"

Waiter::Waiter(std::string name, int totalOrders, FloorColleague *fc) {
    this->name = name;
    this->totalOrders = totalOrders;
    orders = new Order*[totalOrders];
    for (int i = 0; i < totalOrders; i++) {
        orders[i] = nullptr;
    }
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

void Waiter::addOrder(Order* o) {
    busyOrders++;
    if (busyOrders > sizeof(orders)) {
        std::cout << "Waiter: Sorry, I can't take any more orders.\n";
        this->setWaiterState(new WaiterStateUnavailable());
        return;
    }
    orders[busyOrders] = o;
}

void Waiter::setWaiterState(WaiterState* state) {
    this->state = state;
    this->state->setWaiter(this);
}

Order* Waiter::getOrder(RestaurantTable* rt) {
    return rt->getOrder();
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
