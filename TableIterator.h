#ifndef TABLE_ITERATOR_H
#define TABLE_ITERATOR_H

// ConcreteIterator (Iterator)

#include "Iterator.h"

class TableIterator : public Iterator {
    public:
        TableIterator();
        bool hasNext();
        void* next();
};

#endif // TABLE_ITERATOR_H
