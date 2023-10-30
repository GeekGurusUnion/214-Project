#ifndef TABLE_ITERATOR_H
#define TABLE_ITERATOR_H

#include "Table.h"

class TableIterator {
public:
    TableIterator(Table* table) : table_(table), row_(0), col_(0) {}

private:
    Table* table_;
    int row_;
    int col_;
};

#endif // TABLE_ITERATOR_H
