#ifndef TABLE_ITERATOR_H
#define TABLE_ITERATOR_H

// ConcreteIterator (Iterator)

#include "Iterator.h"
#include "RestaurantTable.h"

class TableIterator : public Iterator {
    private:
        // RestaurantTable* restaurantTable;
    public:
        TableIterator();
        bool hasNext();
        void* next();
};

#endif // TABLE_ITERATOR_H
