#ifndef WAITER_ITERATOR_H
#define WAITER_ITERATOR_H
#include <vector>
// ConcreteIterator (Iterator)

#include "Iterator.h"

#include "Waiter.h"
#include <vector>

class WaiterIterator : public Iterator {
    private:
        std::vector<Waiter*> waiters;
        int position;
    public:
        WaiterIterator(std::vector<Waiter*> waiters);
        void* first();
        Waiter* currentItem();
        bool hasNext();
        void* next();
        bool isAvailable();
        ~WaiterIterator();
        bool isAvailable(Waiter* waiter);
};

#endif // WAITER_ITERATOR_H