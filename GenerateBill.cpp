#include "GenerateBill.h"
#include "RestaurantTable.h"

GenerateBill::GenerateBill(Waiter *waiter) : Command(waiter) {}

void GenerateBill::execute(RestaurantTable *rt, MenuItem *m) {
    std::cout << "Generating bill for table " << rt->getTableNumber() << std::endl;
    rt->printBill();
}