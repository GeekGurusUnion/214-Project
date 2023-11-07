#ifndef ORDER_H
#define ORDER_H
// Receiver (Command)

/**
 * @file Order.h
 * @brief Declaration of the Order class representing a customer's order in a restaurant.
 */

#include "MenuItem.h"
#include "RestaurantTable.h"
#include "fa_dish.h"
#include <vector>

/**
 * @class Order
 * @brief A class representing a customer's order in a restaurant.
 *
 * Order defines the characteristics of a customer's order, including the menu items, table, and order status.
 */
class Order {
private:
    std::vector<MenuItem*> items = std::vector<MenuItem*>(); ///< A list of menu items included in the order.
    std::vector<fa_dish*> dishes = std::vector<fa_dish*>(); ///< A list dishes after they have been prepared.
    RestaurantTable* table; ///< A pointer to the restaurant table associated with the order.
    bool status = false; ///< The status of the order (e.g., confirmed or not).
    double total = 0.0; ///< The total cost of the order.

public:
    /**
     * @brief Constructor for the Order class.
     * @param table A pointer to the restaurant table associated with the order.
     */
    Order(RestaurantTable* table);

    /**
     * @brief Destructor for the Order class.
     */
    ~Order();

    /**
     * @brief Add a menu item to the order.
     * @param item A pointer to the menu item to be added.
     */
    void addItem(MenuItem* item);

    /**
     * @brief Set the status of the order (e.g., confirmed or not).
     * @param status The status to set for the order.
     */
    void setStatus(bool status);

    /**
     * @brief Remove a menu item from the order by name.
     * @param name The name of the menu item to remove.
     */
    void removeItem(std::string name);

    /**
     * @brief Get the restaurant table associated with the order.
     * @return A pointer to the restaurant table associated with the order.
     */
    RestaurantTable* getTable();

    /**
     * @brief Get the list of menu items in the order.
     * @return A vector of pointers to the menu items in the order.
     */
    std::vector<MenuItem*> getItems();

    /**
     * @brief Set the list prepared dishes.
     * @param dishes A vector of pointers to prepared dishes.
     */
    void setDishes(std::vector<fa_dish*> dishes);

        /**
     * @brief Get the list prepared dishes.
     * @return A vector of pointers to prepared dishes.
     */
    std::vector<fa_dish*> getDishes();

    /**
     * @brief Add a dish to the list of prepared dishes.
     * @param dish A pointer to the dish to add to the list.
     */
    void addDish(fa_dish* dish);

    /**
     * @brief Add a customization to a specific menu item in the order.
     * @param name The name of the menu item to customize.
     * @param customization The customization to add to the menu item.
     */
    void addCustomization(std::string name, std::string customization);

    // * testing * //
    
    /**
     * @brief Get the size of the order (number of menu items).
     * @return The size of the order.
     */
    int getOrderSize(); 

    /**
     * @brief Calculate the total cost of the order.
    */
    double getTotal();

    /**
     * @brief Add a tip to the order.
    */
    void addTip(double tip);

    /**
     * @brief Split the bill.
    */
    void splitBill(int count);
    
    /**
     * @brief Print the order.
     */
    void printOrder();

    // * end of testing * //
};

#endif // ORDER_H
