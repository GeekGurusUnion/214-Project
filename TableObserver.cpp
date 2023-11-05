#include "TableObserver.h"

TableObserver::TableObserver(RestaurantTable* t)
{
    table = t;
    observerState = table->getState();
}

void TableObserver::update()
{
    observerState = table->getState();
    if(observerState->getState() == "Empty"){

    } 
    else if(observerState->getState() == "Reserved"){
        
    }
    else if(observerState->getState() == "Occupied"){
        //call take order
        if(table->order == NULL){
            table->takeOrder();
        }
    }
    //if order is null, call take order
    
}