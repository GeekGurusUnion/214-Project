#ifndef COMMAND_H
#define COMMAND_H
// Command (Command) [interface]
/**
 * @file Command.h
 * @brief Declaration of the Command class, an interface for the Command pattern.
 */

#include <iostream>

// Forward declarations
class RestaurantTable;
class MenuItem;
class Waiter;

/**
 * @class Command
 * @brief Abstract base class for commands in the Command pattern.
 *
 * Command represents a command to be executed, typically associated with a specific action, and it
 * decouples the sender (Waiter) from the receiver (RestaurantTable and MenuItem).
 */
class Command {
protected:
    Waiter* waiter; ///< A pointer to the Waiter who issues the command.

public:
    /**
     * @brief Constructor for the Command class.
     * @param waiter A pointer to the Waiter issuing the command.
     */
    Command(Waiter* waiter) : waiter(waiter) {};

    /**
     * @brief Execute the command with a RestaurantTable and a MenuItem.
     *
     * This pure virtual function is used to execute the command with a given RestaurantTable and
     * MenuItem, and it must be implemented by concrete command classes.
     *
     * @param rt A pointer to the RestaurantTable on which the command is executed.
     * @param menuItem A pointer to the MenuItem associated with the command.
     */
    virtual void execute(RestaurantTable* rt, MenuItem* menuItem) = 0;

    /**
     * @brief Execute the command with a RestaurantTable, a MenuItem name, and customization details.
     *
     * This virtual function allows executing the command with a RestaurantTable and specifying the
     * MenuItem by its name and providing customization details.
     *
     * @param rt A pointer to the RestaurantTable on which the command is executed.
     * @param menuItem A string representing the name of the MenuItem.
     * @param customization A string specifying any customizations for the MenuItem.
     */
    virtual void execute(RestaurantTable* rt, std::string menuItem, std::string customization) {};

    /**
     * @brief Virtual destructor for the Command class.
     */
    virtual ~Command() {};

    /**
     * @brief Get the Waiter who issued the command.
     * @return A pointer to the Waiter who issued the command.
     */
    virtual Waiter* getWaiter() const {
        return waiter;
    }
};

#endif // COMMAND_H
