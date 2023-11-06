#include "WaiterIterator.h"

WaiterIterator::WaiterIterator(std::vector<Waiter*> waiters) {
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

void WaiterIterator::reset() {
    this->position = 0;
}

// * Testing * //

bool WaiterIterator::getWaiter(std::string name) {
    for (int i = 0; i < this->waiters.size(); i++) {
        if (this->waiters[i]->getName() == name) {
            this->position = i;
            return true;
        }
    }
    return false;
}

// * end of testing * //