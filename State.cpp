#include "State.h"

State::State(RestaurantTable *table) {
    this->table = table;
}

void State::setTable(RestaurantTable *table)
{
    this->table = table;
}