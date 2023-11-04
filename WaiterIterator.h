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
        int position = 0;
    public:
        WaiterIterator(std::vector<Waiter*> waiters);
        ~WaiterIterator();
        void* first();
        Waiter* currentItem();
        bool hasNext();
        void* next();
        bool isAvailable(Waiter* waiter);
        void reset();

        // * Testing
        bool getWaiter(std::string name);
};

#endif // WAITER_ITERATOR_H