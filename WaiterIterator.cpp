#include "WaiterIterator.h"

WaiterIterator::WaiterIterator(std::vector<Waiter*> waiters){
    this->waiters = waiters;
    this->position = 0;
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
        return this->waiters[this->position];
    }
    return nullptr;
};
