#include "Facade.h"

int main() {
    Facade* facade = new Facade();
    facade->getSeated();
    facade->getSeated();
    facade->getSeated();
    facade->getSeated();
    facade->getSeated();
    facade->getSeated();
    facade->addToOrder(0, "Steak");
    facade->addToOrder(12, "Steak");
    return 0;
}
