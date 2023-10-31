#include "TableIterator.h"

TableIterator::TableIterator(std::vector<RestaurantTable*> tables) {
    this->tables = tables;
    this->position = 0;
}

void* TableIterator::first() {
    return tables[0];
}

Table* TableIterator::currentItem() {
    return tables[position];
}

bool TableIterator::hasNext() {
    if (position >= tables.size()) {
        return false;
    }
    return true;
}

void* TableIterator::next() {
    Table* table = tables[position];
    position++;
    return table;
}

bool TableIterator::isAvailable(RestaurantTable* table) {
    return table->isAvailable();
}
