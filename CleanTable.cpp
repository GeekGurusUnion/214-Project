#include "CleanTable.h"

CleanTable::CleanTable(Waiter* waiter) {
    this->waiter = waiter;
}

void CleanTable::execute() {
    this->waiter->cleanUp();
}