#include "MergeTables.h"
#include "RestaurantTable.h"
#include "Facade.h"

MergeTables::MergeTables(Waiter* w) : Command(w) {}

void MergeTables::execute(Facade *f, int count) {
    // get two tables of which the sum of the two getTableSize() will be greater than or equal to the count and both must be available.
    RestaurantTable* table1 = nullptr;
    RestaurantTable* table2 = nullptr;
    int max = 0;
    int sum = 0;
    // first get the max for one table that is available
    f->getTableIterator()->reset();
    RestaurantTable* table = (RestaurantTable*) f->getTableIterator()->next();
    while (table != nullptr) {
        if (!table->isAvailable()) {
            table = (RestaurantTable*) f->getTableIterator()->next();
        } else {
            break;
        }
    }
    if (table == nullptr) {
        // std::cout << "No tables can be merged." << std::endl;
        return;
    }

    while (table != nullptr) {
        if (table->isAvailable() && table->getTableSize() > max) {
            table1 = table;
            max = table->getTableSize();
        }
        if (!f->getTableIterator()->hasNext() && max > 0) {
            break;
        }
        table = (RestaurantTable*) f->getTableIterator()->next();
    }
    if (table1 != nullptr) {
        sum += table1->getTableSize();
    }

    // // std::cout << "max: " << max << std::endl;
    // // std::cout << "sum: " << sum << std::endl;
    // // std::cout << "table1: " << table1 << std::endl;

    // now get the second that are available and have the sum of their table sizes be greater than or equal to the count
    if (table1 != nullptr) {
        f->getTableIterator()->reset();
        table = (RestaurantTable*) f->getTableIterator()->next();
        while (table != nullptr) {
            if (!table->isAvailable()) {
                table = (RestaurantTable*) f->getTableIterator()->next();
            } else {
                break;
            }
        }
        while (table != nullptr) {
            if (table->isAvailable() && table->getTableSize() + max >= count && table != table1) {
                table2 = table;
                sum += table->getTableSize();
                break;
            }
            table = (RestaurantTable*) f->getTableIterator()->next();
        }
    }

    // delete the second table from the facade
    if (table2 != nullptr) {
        table1->setTableSize(count);
        table1->occupy();
        table2->occupy();
        f->getWaiter(table1);
        f->nullifyTable(table2);
        std::cout << "Tables have been merged with new size " << table1->getTableSize() << std::endl;
        std::cout << "Your table number is " << table1->getTableNumber() << std::endl;
    } else {
        // std::cout << "No tables can be merged." << std::endl;
    }
}