#ifndef WAITER_STATE_H
#define WAITER_STATE_H

/**
 * @file WaiterState.h
 * @brief Definition of the WaiterState interface.
 */

/**
 * @class WaiterState
 * @brief Interface representing the state of a Waiter.
 *
 * This is an abstract base class (interface) that defines the state of a Waiter.
 */

// State (State) [interface]

class Waiter;
#include <iostream>

class Waiter;

class WaiterState {
protected:
    /**
     * @var waiter
     * @brief Pointer to the Waiter associated with this state.
     */
    Waiter* waiter;

public:
    /**
     * @brief Constructor for WaiterState.
     * @param waiter Pointer to the Waiter associated with this state.
     */
    WaiterState(Waiter* waiter);

    /**
     * @brief Destructor for WaiterState (virtual to allow for derived class destructors).
     */
    virtual ~WaiterState() {};

    /**
     * @brief Set the associated Waiter object.
     * @param waiter Pointer to the Waiter object.
     */
    void setWaiter(Waiter* waiter);

    /**
     * @brief Set the Waiter's state to available (pure virtual function).
     */
    virtual void setAvailable() = 0;

    /**
     * @brief Set the Waiter's state to unavailable (pure virtual function).
     */
    virtual void setUnavailable() = 0;

    /**
     * @brief Check if the Waiter is available (pure virtual function).
     * @return True if the Waiter is available, false otherwise.
     */
    virtual bool isAvailable() = 0;

    /**
     * @brief Check if the Waiter is unavailable (pure virtual function).
     * @return True if the Waiter is unavailable, false otherwise.
     */
    virtual bool isUnavailable() = 0;

    /**
     * @note The following functions are intended for testing purposes.
     */
    // * testing * //

    /**
     * @brief Get the associated Waiter object.
     * @return Pointer to the Waiter object.
     */
    Waiter* getWaiter() const;

    /**
     * @brief Get a pointer to the current WaiterState object (this) (pure virtual function).
     * @return Pointer to the current WaiterState object.
     */
    virtual WaiterState* getThis() = 0;

    // * end of testing * //
};

#endif // WAITER_STATE_H
