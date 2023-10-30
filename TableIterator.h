#ifndef TABLE_ITERATOR_H
#define TABLE_ITERATOR_H

// ConcreteIterator (Iterator)

#include "Iterator.h"
#include "RestaurantTable.h"
#include <vector>

class TableIterator : public Iterator {
    private:
        std::vector<Table*> tables;
        int position;
    public:
        TableIterator(std::vector<Table*> tables);
        ~TableIterator();

        void* first();
        Table* currentItem();
        bool hasNext();
        void* next();
};

#endif // TABLE_ITERATOR_H
