#ifndef TABLE_ITERATOR_H
#define TABLE_ITERATOR_H

// ConcreteIterator (Iterator)

#include "Iterator.h"
#include "RestaurantTable.h"
#include <vector>

class TableIterator : public Iterator {
    private:
        std::vector<RestaurantTable*> tables;
        int position = 0;
    public:
        TableIterator(std::vector<RestaurantTable*> tables);
        ~TableIterator();
        void* first();
        RestaurantTable* currentItem();
        bool hasNext();
        void* next();
        bool isAvailable(RestaurantTable* table);
        void reset();
};

#endif // TABLE_ITERATOR_H
