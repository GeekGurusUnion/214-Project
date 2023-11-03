#include "WaiterIterator.h"

WaiterIterator::WaiterIterator(std::vector<Waiter*> waiters) {
    std::cout << "Constructor" << std::endl;
    this->waiters = waiters;
    this->position = 0;
};

WaiterIterator::~WaiterIterator() {
    std::cout << "Destructor" << std::endl;
    this->waiters.clear();
};

void* WaiterIterator::first(){
    return this->waiters[0];
};

Waiter* WaiterIterator::currentItem(){
    return this->waiters[this->position];
};

bool WaiterIterator::hasNext(){
    if(this->position < this->waiters.size()){
        return true;
    }
    return false;
};

void* WaiterIterator::next(){
    if(this->hasNext()){
        this->position++;
        if (this->position >= waiters.size())
            return nullptr;
        return this->waiters[this->position];
    }
    return nullptr;
};

bool WaiterIterator::isAvailable(Waiter *waiter) {
    return waiter->isAvailable();
}

void WaiterIterator::reset() {
    this->position = 0;
}
