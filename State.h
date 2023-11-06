#ifndef STATE_H_
#define STATE_H_
// State (State) [interface]

/**
 * @file State.h
 * @brief Definition of the State class.
 */

#include <iostream> 
// Forward declaration
class RestaurantTable;

/**
 * @class State
 * @brief Represents a state of a RestaurantTable.
 *
 * This class is an interface for representing the different states of a RestaurantTable,
 * such as "Serve," "Occupied," or "Empty."
 */
class State {
protected:
    /**
     * @var table
     * @brief Pointer to the associated RestaurantTable.
     */
    RestaurantTable* table = nullptr;

    /**
     * @var stateName
     * @brief The name of the state.
     */
    std::string stateName;

public:
    /**
     * @brief Constructor for State.
     * @param table Pointer to the RestaurantTable associated with this state.
     */
    State(RestaurantTable* table);

    /**
     * @brief Destructor for State.
     */
    virtual ~State();

    /**
     * @brief Set the associated RestaurantTable.
     * @param table Pointer to the RestaurantTable.
     */
    void setTable(RestaurantTable* table);

    /**
     * @brief Transition the table to the "Serve" state.
     */
    virtual void serve() = 0;

    /**
     * @brief Transition the table to the "Occupied" state.
     */
    virtual void occupy() = 0;

    /**
     * @brief Transition the table to the "Empty" state.
     */
    virtual void empty() = 0;

    /** 
     * @brief Handle the order.
    */
    virtual void handleOrder() = 0;

    /**
     * @brief Get the name of the current state.
     * @return A string representing the state name.
     */
    virtual std::string getStateName() = 0;

    /**
     * @brief Check if the table is in the "Occupied" state.
     * @return True if the table is occupied, false otherwise.
     */
    virtual bool isOccupied() = 0;
};

#include "StateEmpty.h"
#include "StateOccupied.h"
#include "StateServe.h"

#endif  // STATE_H_
