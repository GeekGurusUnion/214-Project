#include "Facade.h"

int main() {
    Facade* facade = new Facade();
    for (int i = 1; i <= 13; i++) {
        facade->getSeated();
    }
    facade->addToOrder(1, "Steak");
    facade->addToOrder(12, "Spinach");
    facade->addToOrder(12, "Steak");
    facade->addToOrder(12, "Steak");
    facade->addToOrder(12, "Burger");
    facade->confirmOrder(12);
    facade->generateBill(12);
    facade->leaveTable(12);
    delete facade;
    return 0;
}
