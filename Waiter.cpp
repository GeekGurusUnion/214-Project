#include "Waiter.h"

Waiter::Waiter(int id) {
    this->waiterId = id;
}

// TODO: Figure out a way to add to the Order obj stack (build the order)
void Waiter::placeOrder() {

}

// TODO: Clean up the table -> will happen when customers leave (or RestaurantTable state is empty)
void Waiter::cleanUp() {

}

// TODO: Needs to be send to Mediator (Concrete Colleague)
void Waiter::confirmOrder() {

}