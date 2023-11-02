#include "TableIterator.h"

TableIterator::TableIterator(std::vector<RestaurantTable*> tables) {
    std::cout << "Constructor" << std::endl;
    this->tables = tables;
    this->position = 0;
}

TableIterator::~TableIterator() {
    std::cout << "Destructor" << std::endl;
    tables.clear();
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

void TableIterator::reset() {
    this->position = 0;
}
