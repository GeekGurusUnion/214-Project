#include "Waiter.h"
#include "WaiterStateAvailable.h"
#include "WaiterStateUnavailable.h"

Waiter::Waiter(std::string name, int totalOrders, FloorColleague *fc) {
    this->name = name;
    this->totalOrders = totalOrders;

    menu.push_back(new MenuItem("Chicken", 10.99));
    menu.push_back(new MenuItem("Burger", 12.99));
    menu.push_back(new MenuItem("Pork", 11.99));
    menu.push_back(new MenuItem("Fish", 13.99));
    menu.push_back(new MenuItem("Lamb", 14.99));
    menu.push_back(new MenuItem("Pasta", 15.99));
    menu.push_back(new MenuItem("Pizza", 16.99));
    menu.push_back(new MenuItem("Salad", 17.99));
    menu.push_back(new MenuItem("Soup", 18.99));
    menu.push_back(new MenuItem("Steak", 19.99));

    this->state = new WaiterStateAvailable(this);
    this->cO = new ConfirmOrder(this, fc);
    this->tO = new TakeOrder(this);
    this->gB = new GenerateBill(this);
    this->aC = new CustomizeOrder(this);
}

Waiter::~Waiter() {
    for (MenuItem* item : menu) {
        delete item;
    }
    menu.clear();

    delete cO;
    delete tO;
    delete gB;

    tables.clear();

    delete state;
}

void Waiter::addItem(RestaurantTable* rt, std::string m) { 
    MenuItem* menuItem = this->getMenuItem(m);
    if (menuItem != nullptr) {
        tO->execute(rt, menuItem);
    }
}

void Waiter::confirmOrder(RestaurantTable* rt) {
    cO->execute(rt, nullptr);
}

void Waiter::addOrder(RestaurantTable* rt) {
    if (!isAvailable()) {
        std::cout << "Waiter: Sorry, I can't take any more orders.\n";
        return;
    }
    this->busyOrders++;
    tables.push_back(rt);
    if (busyOrders == totalOrders) {
        std::cout << "Waiter: This will be the last one.\n";
        this->state->setUnavailable();
    }
}

void Waiter::setWaiterState(WaiterState* state) {
    delete this->state;
    this->state = state;
}

Order* Waiter::getOrder(RestaurantTable* rt) {
    for (auto& t : tables) {
        if (t == rt) {
            return t->getOrder();
        }
    }
    return nullptr;
}

bool Waiter::isAvailable() {
    return this->state->isAvailable();
}

std::string Waiter::getName() const {
    return this->name;
}

void Waiter::generateBill(RestaurantTable *rt) {
    gB->execute(rt, nullptr);
}

int Waiter::getBusyOrders() const {
    return this->busyOrders;
}

void Waiter::addCustomization(RestaurantTable *rt, std::string name, std::string customization) {
    aC->execute(rt, name, customization);
}

MenuItem* Waiter::getMenuItem(std::string name) {
    for (int i = 0; i < menu.size(); i++) {
        if (menu[i]->getName() == name) {
            return menu[i];
        }
    }
    return nullptr;
}

// * testing * //
int Waiter::getTotalOrders() const {
    return this->totalOrders;
}

WaiterState* Waiter::getState() const {
    return this->state;
}

std::vector<RestaurantTable*> Waiter::getTables() const {
    return this->tables;
}

std::vector<MenuItem*> Waiter::getMenu() const {
    return this->menu;
}

Command* Waiter::getCO() const {
    return this->cO;
}

Command* Waiter::getTO() const {
    return this->tO;
}

void Waiter::setState(WaiterState* state) {
    this->state = state;
}
// * end of testing * //