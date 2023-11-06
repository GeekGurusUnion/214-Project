#ifndef STATE_EMPTY_H_
#define STATE_EMPTY_H_

/**
 * @file StateEmpty.h
 * @brief Definition of the StateEmpty class.
 */

/**
 * @class StateEmpty
 * @brief Represents the "Empty" state of a RestaurantTable.
 *
 * This class is a concrete implementation of the State interface,
 * representing the state where a RestaurantTable is empty and available.
 */

// ConcreteState (State)

#include "State.h"
#include <iostream> 

class StateEmpty : public State {
public:
    /**
     * @brief Constructor for StateEmpty.
     * @param table Pointer to the RestaurantTable associated with this state.
     */
    StateEmpty(RestaurantTable* table);

    /**
     * @brief Destructor for StateEmpty.
     */
    ~StateEmpty() {};

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

#endif  // STATE_EMPTY_H_
