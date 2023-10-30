#ifndef WAITER_ITERATOR_H
#define WAITER_ITERATOR_H

// ConcreteIterator (Iterator)

#include "Iterator.h"

class WaiterIterator : public Iterator {
    public:
        WaiterIterator() {}
        bool hasNext();
        void* next();
};

#endif // WAITER_ITERATOR_H