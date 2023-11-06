#ifndef MENUITEM_H
#define MENUITEM_H

/**
 * @file MenuItem.h
 * @brief Declaration of the MenuItem class representing a menu item in a restaurant.
 */

#include <string>
#include <vector>
#include <iostream>

/**
 * @class MenuItem
 * @brief A class representing a menu item in a restaurant.
 *
 * MenuItem defines the characteristics of a menu item, including its name, price, and available customizations.
 */
class MenuItem {
private:
    std::string name; ///< The name of the menu item.
    std::vector<std::string> customizations = {}; ///< A list of available customizations for the menu item.
    double price; ///< The price of the menu item.

public:
    /**
     * @brief Constructor for the MenuItem class.
     * @param name The name of the menu item.
     * @param price The price of the menu item.
     */
    MenuItem(std::string name, double price);

    /**
     * @brief Destructor for the MenuItem class.
     */
    ~MenuItem();

    /**
     * @brief Copy constructor for the MenuItem class.
     * @param other Another MenuItem object to copy from.
     */
    MenuItem(const MenuItem& other);

    /**
     * @brief Get the name of the menu item.
     * @return The name of the menu item.
     */
    std::string getName();

    /**
     * @brief Get the price of the menu item.
     * @return The price of the menu item.
     */
    double getPrice();

    /**
     * @brief Add a customization option to the menu item.
     * @param customization The customization option to add.
     */
    void addCustomization(std::string customization);

    /**
     * @brief Check if the menu item contains a specific customization.
     * @param customization The customization to check for.
     * @return `true` if the menu item contains the specified customization, `false` otherwise.
     */
    bool containsCustomization(std::string customization);

    std::vector<std::string> getCustomizations();
};

#endif // MENUITEM_H
