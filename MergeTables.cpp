#include "MergeTables.h"
#include "RestaurantTable.h"
#include "Facade.h"

MergeTables::MergeTables(Waiter* w) : Command(w) {}

void MergeTables::execute(Facade *f, int count) {
    RestaurantTable* rt = nullptr;
    RestaurantTable* rt2 = nullptr;
    int currCount = 0;
    int tablesFound = 0;
    for (int i = 0; i < f->getTotalTables(); i++) {
        if (f->getTable(i)->isAvailable()) {
            if (tablesFound == 0) {
                rt = f->getTable(i);
                currCount = rt->getTableSize();
                tablesFound++;
            } else if (tablesFound == 1) {
                rt2 = f->getTable(i);
                currCount += rt2->getTableSize();
                tablesFound++;
            } else {
                break;
            }
        }
    }
    if (tablesFound == 2) {
        rt->setTableSize(currCount);;
        f->removeTable(rt2);
    } else {
        std::cout << "Not enough tables available to merge." << std::endl;
    }
}