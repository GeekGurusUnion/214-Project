#ifndef WAITER_STATE_AVAILABLE_H
#define WAITER_STATE_AVAILABLE_H

/**
 * @file WaiterStateAvailable.h
 * @brief Definition of the WaiterStateAvailable class.
 */

// ConcreteState (State)

#include "WaiterState.h"

/**
 * @class WaiterStateAvailable
 * @brief Represents the available state of a Waiter.
 *
 * This class is a concrete implementation of the WaiterState interface,
 * representing the state where a Waiter is available.
 */
class WaiterStateAvailable : public WaiterState {
public:
    /**
     * @brief Constructor for WaiterStateAvailable.
     * @param waiter Pointer to the Waiter associated with this state.
     */
    WaiterStateAvailable(Waiter* waiter);

    /**
     * @brief Check if the Waiter is available.
     * @return True if the Waiter is available, false otherwise.
     */
    bool isAvailable();

    /**
     * @brief Check if the Waiter is unavailable.
     * @return True if the Waiter is unavailable, false otherwise.
     */
    bool isUnavailable();

    /**
     * @brief Set the Waiter's state to available.
     */
    void setAvailable();

    /**
     * @brief Set the Waiter's state to unavailable.
     */
    void setUnavailable();

    /**
     * @note The following functions are intended for testing purposes.
     */
    // * testing * //

    /**
     * @brief Get the associated Waiter object.
     * @return Pointer to the Waiter object.
     */
    Waiter* getWaiter() const { return nullptr; };

    /**
     * @brief Get a pointer to the current WaiterState object (this).
     * @return Pointer to the current WaiterState object.
     */
    WaiterState* getThis();

    /**
     * @var currState
     * @brief A string representing the current state ("WaiterStateAvailable").
     */
    std::string currState = "WaiterStateAvailable";

    // * end of testing * //
};

#endif // WAITER_STATE_AVAILABLE_H
