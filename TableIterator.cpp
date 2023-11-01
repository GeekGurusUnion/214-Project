#include "TableIterator.h"

TableIterator::TableIterator(std::vector<RestaurantTable*> tables) {
    this->tables = tables;
    this->position = 0;
}

void* TableIterator::first() {
    return tables[0];
}

RestaurantTable* TableIterator::currentItem() {
    return tables[position];
}

bool TableIterator::hasNext() {
    if (position >= tables.size()) {
        return false;
    }
    return true;
}

void* TableIterator::next() {
    if (position >= tables.size()) {
        return nullptr;
    }
    RestaurantTable* table = tables[position];
    position++;
    if (table == nullptr) {
        return nullptr;
    }
    return table;
}

bool TableIterator::isAvailable(RestaurantTable* table) {
    return table != nullptr && table->isAvailable();
}
