#ifndef FACADE_H
#define FACADE_H

// Facade (Facade)

#include "RestaurantTable.h"
#include "TableIterator.h"
#include "WaiterIterator.h"
#include <vector>

class Facade {
    private:
        Iterator* waiterIterator = new WaiterIterator();
        Iterator* tableIterator = new TableIterator();
        std::vector<Table*> tables;
    public:
        Facade(int tableSize) {
            for (int i = 0; i < tableSize; i++) {
                tables.push_back(new RestaurantTable());
            }
        }
        Iterator* getWaiterIterator() {
            return waiterIterator;
        }
        Iterator* getTableIterator() {
            return tableIterator;
        }
        Table* getTable(int index) {
            return tables[index];
        }

        void getSeated() {
            while (waiterIterator->hasNext()) {
                RestaurantTable* table = waiterIterator->next();
                table->setState((State*) new StateOccupied());
            }
        }




};

#endif // FACADE_H
