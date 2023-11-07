#include "Facade.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

int seatPeople(Facade* facade) {
    cout << "\n------------------------" << std::endl;
    cout << "Please enter the number of people you wish to seat: ";
    int numPeople;
    cin >> numPeople;
    int tN = facade->getSeated(numPeople);
    return tN;
}

int checkTableNumber(Facade* facade) {
    cout << "\n------------------------" << std::endl;
    int tableNumber;
    int counter = 0;
    while (true) {
        if (counter == 0) {
            cout << "Please enter the table number you wish to order from: ";
            counter++;
        }
        else {
            cout << "Please enter your table number: ";
        }
        cin >> tableNumber;
        if (facade->getTable(tableNumber)->getWaiter() == nullptr) {
            cout << "Table " << tableNumber << " is not occupied!" << std::endl;
        } else {
            break;
        }
    }
    return tableNumber;
}

bool isPizza(std::string orderItem) {
    return (orderItem == "BBQChickenPizza" || orderItem == "PepperoniPizza" || orderItem == "HawaiianPizza");
}

void printCustomizations(Facade* facade, int tableNumber, std::string orderItem) {
    cout << "\nCustomizations:" << std::endl;
    cout << "---------------" << std::endl;

    while (true) {
        cout << "\nPlease select the customization you wish to add to your order from the list below" << std::endl;
        std::string customization;
        int customizationChoice;

        if (isPizza(orderItem)) {
            cout << "1. Extra Cheese" << std::endl;
            if (orderItem == "BBQChickenPizza") {
                cout << "2. Extra Bacon" << std::endl;
                cout << "3. No Bacon" << std::endl;
            }
            else if (orderItem == "PepperoniPizza") {
                cout << "2. Extra Garlic" << std::endl;
                cout << "3. No Garlic" << std::endl;
            }
            else if (orderItem == "HawaiianPizza") {
                cout << "2. Extra Pineapple" << std::endl;
                cout << "3. No Pineapple" << std::endl;
            }
        } else {
            cout << "1. Extra Cheese" << std::endl;
            if (orderItem == "ChickenBurger") {
                cout << "2. No Pickles" << std::endl;
            }
        }

        cout << "\nYour choice: ";
        cin >> customizationChoice;

        while (customizationChoice < 1 || customizationChoice > 3) {
            cout << "Please select the correct choice: ";
            cin >> customizationChoice;
        }

        // Set the customization based on the user's choice
        if (isPizza(orderItem)) {
            switch (customizationChoice) {
                case 1:
                    customization = "ExtraCheese";
                    break;
                case 2:
                    if (orderItem == "BBQChickenPizza") {
                        customization = "ExtraBacon";
                    } else if (orderItem == "PepperoniPizza") {
                        customization = "ExtraGarlic";
                    } else if (orderItem == "HawaiianPizza") {
                        customization = "ExtraPineapple";
                    }
                    break;
                case 3:
                    if (orderItem == "BBQChickenPizza") {
                        customization = "NoBacon";
                    } else if (orderItem == "PepperoniPizza") {
                        customization = "NoGarlic";
                    } else if (orderItem == "HawaiianPizza") {
                        customization = "NoPineapple";
                    }
                    break;
                default:
                    cout << "Invalid option selected." << std::endl;
                    break;
            }
        } else {
            switch (customizationChoice) {
                case 1:
                    customization = "ExtraCheese";
                    break;
                case 2:
                    if (orderItem == "ChickenBurger") {
                        customization = "NoPickles";
                    }
                    break;
                default:
                    cout << "Invalid option selected." << std::endl;
                    break;
            }
        }

        facade->addCustomization(tableNumber, orderItem, customization);

        cout << "\nDo you want to add another customization? (y/n): ";

        char customizationCheck;
        cin >> customizationCheck;

        // Check if the customizationCheck is correct
        while (customizationCheck != 'y' && customizationCheck != 'n') {
            cout << "Please select the correct choice (y/n): ";
            cin >> customizationCheck;
        }

        if (customizationCheck == 'n') {
            break;
        }
    }
}

void printMenu(Facade* facade, int tableNumber) {
    cout << "\nTaking an order for Table " << tableNumber << std::endl;
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

        // Determine the orderItem based on the foodChoice and foodItem
        std::string orderItem = (foodChoice == 1) ? "Pizza" : "Burger";
        switch (foodItem) {
            case 1:
                orderItem = (foodChoice == 1) ? "BBQChickenPizza" : "BeefBurger";
                break;
            case 2:
                orderItem = (foodChoice == 1) ? "PepperoniPizza" : "ChickenBurger";
                break;
            case 3:
                orderItem = (foodChoice == 1) ? "HawaiianPizza" : "DoubleBurger";
                break;
        }

        char customizationChoice;
        cout << "\nDo you want to customize your item? (y/n): ";
        cin >> customizationChoice;

        // Check if the customizationChoice is correct
        while (customizationChoice != 'y' && customizationChoice != 'n') {
            cout << "Please select the correct choice (y/n): ";
            cin >> customizationChoice;
        }

        // Add the item to the order
        facade->addToOrder(tableNumber, orderItem);

        if (customizationChoice == 'y') {
            printCustomizations(facade, tableNumber, orderItem);
        }

        cout << "\n------------------------" << endl;
        cout << "Do you want to add another item to your order? (y/n): ";
        char addItem;
        cin >> addItem;

        // Check if the addItem is correct
        while (addItem != 'y' && addItem != 'n') {
            cout << "Please select the correct choice (y/n): ";
            cin >> addItem;
        }

        if (addItem == 'n') {
            break;
        }
    }
}

void orderFood(Facade* facade, int tableNumber) {
    printMenu(facade, tableNumber);
}

int main() {
    Facade* facade = new Facade();

    cout << "Welcome to the Burger and Pizza Joint!" << std::endl;
    int numGroups;
    cout << "Please enter the number of groups you wish to seat: ";
    cin >> numGroups;

    std::vector<int> tableNumbers = {};
    std::vector<int> tableBills =  {};

    for (int i = 0; i < numGroups; i++) {
        cout << "\nSeating group: " << i + 1 << std::endl;
        int tN = seatPeople(facade);
        tableBills.push_back(tN);
        cout << "\n------------------------" << std::endl;
        cout << "Do you wish to take your order now? (y/n): ";
        char orderChoice;
        cin >> orderChoice;

        if (orderChoice == 'n') {
            tableNumbers.push_back(tN);
            cout << "We will be back in 5 minutes to take your order" << std::endl;
        } else {
            orderFood(facade, tN);
        }
    }

    while (!tableNumbers.empty()) {
        int num = tableNumbers.front();
        cout << "\nTable " << num << ", are you ready to order? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'n') {
            cout << "We will be back in 5 minutes to take your order" << std::endl;
            continue;
        }
        orderFood(facade, num);
        tableNumbers.erase(tableNumbers.begin());
    }

    for (int i : tableBills) {
        facade->confirmOrder(i);
    }

    for (int i : tableBills) {
        facade->generateBill(i);

        cout << "\nTable " << i << " would you like to tip? (y/n): ";
        char choice;
        cin >> choice;

        // Check if the choice is correct
        while (choice != 'y' && choice != 'n') {
            cout << "Please select the correct choice (y/n): ";
            cin >> choice;
        }

        // Add a tip if the choice is 'y'
        if (choice == 'y') {
            cout << "How much would you like to tip? (Enter a number - this will be a percentage): ";
            double tip;
            cin >> tip;
            facade->tip(i, tip);
        }

        cout << "\nTable " << i << " would you like to split the bill? (y/n): ";
        cin >> choice;

        // Check if the choice is correct
        while (choice != 'y' && choice != 'n') {
            cout << "Please select the correct choice (y/n): ";
            cin >> choice;
        }

        if (choice == 'y') {
            cout << "How many people would you like to split the bill with? ";
            int numPeople;
            cin >> numPeople;
            facade->splitBill(i, numPeople);
        }

        cout << "\nTable " << i << " would you like to leave a complaint? (y/n): ";
        cin >> choice;

        // Check if the choice is correct
        while (choice != 'y' && choice != 'n') {
            cout << "Please select the correct choice (y/n): ";
            cin >> choice;
        }

        if (choice == 'y') {
            std::string complaint;
            cout << "Please leave a description of your complaint: ";
            cin.ignore(); // Ignore newline character left in the input buffer
            getline(cin, complaint);
            facade->complain(i, complaint);
        }
        facade->payBill(i);
    }

    delete facade;
    return 0;
}
