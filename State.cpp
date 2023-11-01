#include "State.h"
#include "RestaurantTable.h"

State::State(RestaurantTable *table) {
    this->table = table;
}

State::~State() {
    delete table;
}

void State::setTable(RestaurantTable *table)
{
    this->table = table;
}