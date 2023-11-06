#ifndef STATE_OCCUPIED_H_
#define STATE_OCCUPIED_H_

/**
 * @file StateOccupied.h
 * @brief Definition of the StateOccupied class.
 */

/**
 * @class StateOccupied
 * @brief Represents the "Occupied" state of a RestaurantTable.
 *
 * This class is a concrete implementation of the State interface,
 * representing the state where a RestaurantTable is occupied by customers.
 */


// ConcreteState (State)

#include "State.h"
#include <iostream> 

class RestaurantTable;

class StateOccupied : public State {
public:
    /**
     * @brief Constructor for StateOccupied.
     * @param table Pointer to the RestaurantTable associated with this state.
     */
    StateOccupied(RestaurantTable* table);

    /**
     * @brief Destructor for StateOccupied.
     */
    ~StateOccupied() {};

    /**
     * @brief Transition the table to the "Serve" state.
     */
    void serve();

    /**
     * @brief Transition the table to the "Occupied" state.
     */
    void occupy();

    /**
     * @brief Transition the table to the "Empty" state.
     */
    void empty();

    /**
     * @brief Transition the table to the "Handle Order" state.
     */
    void handleOrder() {};

    /**
     * @brief Get the name of the current state.
     * @return A string representing the state name.
     */
    std::string getStateName();

    /**
     * @brief Check if the table is in the "Occupied" state.
     * @return True if the table is occupied, false otherwise.
     */
    bool isOccupied();
};

#endif  // STATE_OCCUPIED_H_
