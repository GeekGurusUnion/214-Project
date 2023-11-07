#ifndef COMPLAINTS_H
#define COMPLAINTS_H

/**
 * @file Complaints.h
 * @brief Declaration of the Complaints class representing a command that allows a waiter to register a complaint from a customer.
 
*/

#include "Command.h"
// ConcreteCommand (Command)

/**
 * @class Complaints
 * @brief A class representing a command that allows a waiter to register a complaint from a customer.
*/
class Complaints : public Command {
public:
    /**
     * @brief Constructs a new Complaints object.
     * 
     * @param w The waiter who will register the complaint.
     */
    Complaints(Waiter* w);

    /**
     * @brief Executes the Complaints command by registering a complaint from a customer.
     * 
     * @param rt The table where the complaint was made.
     * @param complaint The complaint made by the customer.
     */
    void execute(RestaurantTable* rt, std::string complaint);
};

#endif // COMPLAINTS_H