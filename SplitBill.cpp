#include "SplitBill.h"
#include "RestaurantTable.h"

SplitBill::SplitBill(Waiter* w) : Command(w) {}

void SplitBill::execute(RestaurantTable *rt, double count) {
    rt->setCostPerPerson(count);
}