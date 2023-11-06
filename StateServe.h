#ifndef STATE_RESERVED_H_
#define STATE_RESERVED_H_

/**
 * @file StateReserved.h
 * @brief Definition of the StateReserved class.
 */

/**
 * @class StateReserved
 * @brief Represents the "Reserved" state of a RestaurantTable.
 *
 * This class is a concrete implementation of the State interface,
 * representing the state where a RestaurantTable is reserved.
 */

// ConcreteState (State)

#include "State.h"
#include <iostream> 

class StateServe : public State {
public:
    /**
     * @brief Constructor for StateServe.
     * @param table Pointer to the RestaurantTable associated with this state.
     */
    StateServe(RestaurantTable* table);

    /**
     * @brief Destructor for StateServe.
     */
    ~StateServe() {};

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

#endif  // STATE_RESERVED_H_
