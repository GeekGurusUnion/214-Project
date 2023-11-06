#include "Facade.h"
#include <iostream>
#include <string>

int main() {
    Facade* facade = new Facade();
    for (int i = 1; i <= 13; i++) {
        if (i <= 4)
            facade->getSeated(5);
        if (i > 4 && i <= 8)
            facade->getSeated(4);
        if (i > 8 && i <= 12)
            facade->getSeated(2);
    }
    facade->addToOrder(1, "Steak");
    facade->addToOrder(12, "Spinach");
    facade->addToOrder(12, "Steak");
    facade->addToOrder(12, "Steak");
    facade->addToOrder(12, "Burger");
    facade->addCustomization(12, "Steak", "Medium");
    facade->addCustomization(12, "Steak", "Medium");
    facade->confirmOrder(12);
    facade->generateBill(12);
    facade->leaveTable(12);
    delete facade;
    return 0;
}