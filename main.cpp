#include "Facade.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

void seatPeople(Facade* facade) {
    cout << "\n------------------------" << std::endl;
    cout << "Please enter the number of people you wish to seat: ";
    int numPeople;
    cin >> numPeople;
    facade->getSeated(numPeople);
}
// Checking if the table number entered is correct
int checkTableNumber(Facade* facade) {
    cout << "\n------------------------" << std::endl;
    int tableNumber;
    int counter = 0;
    while (true) {
        if (counter == 0) {
            cout << "Please enter the table number you wish to order from: ";
            counter++;
        }
        else 
            cout << "Please enter your table number: ";
        cin >> tableNumber;
        if (facade->getTable(tableNumber)->getWaiter() == nullptr) {
            cout << "Table " << tableNumber << " is not occupied!" << std::endl;
            continue;
        } else {
            break;
        }
    }
    return tableNumber;
}

bool isPizza(std::string orderItem) {
    if (orderItem == "BBQChickenPizza" || orderItem == "PepperoniPizza" || orderItem == "HawaiianPizza")
        return true;
    return false;
}

void printCustomizations(Facade* facade, int tableNumber, std::string orderItem) {
    cout << "\nCustomizations:" << std::endl;
    cout << "---------------" << std::endl;

    // change this if else to add multiple customizations
    while (true) {
        cout << "\nPlease select the you wish to add to your order from the list below" << std::endl;
        std::string customization;
        int customizationChoice;
        if (isPizza(orderItem)) {
            cout << "1. Extra Cheese" << std::endl;
            if (orderItem == "BBQChickenPizza") {
                cout << "2. Extra Bacon" << std::endl;
                cout << "3. No Bacon" << std::endl;
                cout << "\nYour choice: ";
                cin >> customizationChoice;
                // set the customization to the correct customization
                switch (customizationChoice) {
                    case 1:
                        customization = "ExtraCheese";
                        break;
                    case 2:
                        customization = "ExtraBacon";
                        break;
                    case 3:
                        customization = "NoBacon";
                        break;
                }
            }
            if (orderItem == "PepperoniPizza") {
                cout << "2. Extra Garlic" << std::endl;
                cout << "3. No Garlic" << std::endl;
                cout << "\nYour choice: ";
                cin >> customizationChoice;
                //set the customization to the correct customization
                switch(customizationChoice) {
                    case 1:
                        customization = "ExtraCheese";
                        break;
                    case 2:
                        customization = "ExtraGarlic";
                        break;
                    case 3:
                        customization = "NoGarlic";
                        break;
                }
            }
            if (orderItem == "HawaiianPizza") {
                cout << "2. Extra Pineapple" << std::endl;
                cout << "3. No Pineapple" << std::endl;
                cout << "\nYour choice: ";
                cin >> customizationChoice;
                //set the customization to the correct customization
                switch(customizationChoice) {
                    case 1:
                        customization = "ExtraCheese";
                        break;
                    case 2:
                        customization = "ExtraPineapple";
                        break;
                    case 3:
                        customization = "NoPineapple";
                        break;
                }
            }
        } else {
            cout << "1. Extra Cheese" << std::endl;
            if (orderItem == "ChickenBurger")
                cout << "2. No Pickles" << std::endl;
            cout << "\nYour choice: ";
            cin >> customizationChoice;
            // set the customization to the correct customization
            switch (customizationChoice) {
                case 1:
                    customization = "ExtraCheese";
                    break;
                case 2:
                    customization = "NoPickles";
            }
        }
        facade->addCustomization(tableNumber, orderItem, customization);

        cout << "\nDo you want to add another customization? (y/n): ";

        char customizationCheck;
        cin >> customizationCheck;

        // checking if the customizationCheck is correct
        while (customizationCheck != 'y' && customizationCheck != 'n') {
            cout << "Please select the correct choice (y/n): ";
            cin >> customizationCheck;
        }

        if (customizationCheck == 'n')
            break;
    }
}

void printMenu(Facade* facade, int tableNumber) {
    cout << "\nMenu:" << std::endl;

    while (true) {

        cout << "-----" << std::endl;
        cout << "Please select 1 for Pizzas and 2 for Burgers: ";
        int foodChoice;
        cin >> foodChoice;
        // Checking if the foodChoice is correct
        while (foodChoice != 1 && foodChoice != 2) {
            cout << "Please select the correct choice: ";
            cin >> foodChoice;
        }

        // Printing the menu either for pizzas or burgers
        std::string foodType = (foodChoice == 1) ? "Pizza" : "Burger";
        cout << "\nPlease select the " << foodType << " you wish to order from the list below" << std::endl;
        if (foodChoice == 1) {
            cout << "1. BBQ Chicken Pizza - a BBQ Chicken Pizza with bacon and green pepper" << std::endl;
            cout << "2. Pepperoni Pizza - classic Pepperoni with added garlic" << std::endl;
            cout << "3. Hawaiian Pizza - the old pineapple and ham" << std::endl;
        } else {
            cout << "1. Beef Burger - original style" << std::endl;
            cout << "2. Chicken Burger - chicken breast with added pickles" << std::endl;
            cout << "3. Double Burger - two stacked beef patties (for the brave)" << std::endl;
        }

        cout << "\nYour choice: ";
        int foodItem;
        cin >> foodItem;
        while (foodItem < 1 || foodItem > 3) {
            cout << "Please select the correct choice: ";
            cin >> foodItem;
        }

        // orderItem based on the foodChoice and foodItem
        std::string orderItem = "";
        if (foodChoice == 1) {
            switch (foodItem) {
                case 1:
                    orderItem = "BBQChickenPizza";
                    break;
                case 2:
                    orderItem = "PepperoniPizza";
                    break;
                case 3:
                    orderItem = "HawaiianPizza";
                    break;
            }
        } else {
            switch (foodItem) {
                case 1:
                    orderItem = "BeefBurger";
                    break;
                case 2:
                    orderItem = "ChickenBurger";
                    break;
                case 3:
                    orderItem = "DoubleBurger";
                    break;
            }
        }

        char customizationChoice;
        cout << "\nDo you want to customize your item? (y/n): ";
        cin >> customizationChoice;

        // checking if the customizationChoice is correct
        while (customizationChoice != 'y' && customizationChoice != 'n') {
            cout << "Please select the correct choice (y/n): ";
            cin >> customizationChoice;
        }

        // add the item to the order
        facade->addToOrder(tableNumber, orderItem);

        if (customizationChoice == 'y') 
            printCustomizations(facade, tableNumber, orderItem);
        
        cout << "\n------------------------" << endl;
        cout << "Do you want to add another item to your order? (y/n): ";
        char addItem;
        cin >> addItem;

        // checking if the addItem is correct
        while (addItem != 'y' && addItem != 'n') {
            cout << "Please select the correct choice (y/n): ";
            cin >> addItem;
        }
        if (addItem == 'n') {
            facade->confirmOrder(tableNumber);
            break;
        }
    }
}

void orderFood(Facade* facade) {
    int tableNumber = checkTableNumber(facade);
    printMenu(facade, tableNumber);
}

int main() {
    Facade* facade = new Facade();
    cout << "Welcome to the Burger and Pizza Joint!" << std::endl;
    int numGroups;
    cout << "Please enter the number of groups you wish to seat: ";
    cin >> numGroups;

    for (int i = 0; i < numGroups; i++) {
        cout << "Seating group: " << i + 1 << std::endl;
        seatPeople(facade); 
        orderFood(facade);
    }
    



    //* Old main
    // for (int i = 1; i <= 13; i++) {
    //     if (i <= 4)
    //         facade->getSeated(5);
    //     if (i > 4 && i <= 8)
    //         facade->getSeated(4);
    //     if (i > 8 && i <= 12)
    //         facade->getSeated(2);
    // }
    // facade->addToOrder(1, "Steak");
    // facade->addToOrder(12, "Spinach");
    // facade->addToOrder(12, "Steak");
    // facade->addToOrder(12, "Steak");
    // facade->addToOrder(12, "Burger");
    // facade->addCustomization(12, "Steak", "Medium");
    // facade->addCustomization(12, "Steak", "Medium");
    // facade->confirmOrder(12);
    // facade->generateBill(12);
    // facade->leaveTable(12);
    // delete facade;
    delete facade;
    return 0;
}