#ifndef TABLEOBSERVER_H
#define TABLEOBSERVER_H
#include "Observer.h"
#include "RestaurantTable.h"
#include "State.h"
// concrete observer
class TableObserver:public Observer
{
    public:
        TableObserver(RestaurantTable* t);
        void update();
    private:
        RestaurantTable* table;
        //observer state
        State* observerState;
};
#endif // !TABLEOBSERVER_H