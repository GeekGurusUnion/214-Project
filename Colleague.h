#ifndef COLLEAGUE_H
#define COLLEAGUE_H
// Colleague (Mediator) [interface]
/**
 * @file Colleague.h
 * @brief Declaration of the Colleague class, an interface for Mediator pattern.
 */

// Forward declarations
class Mediator;
class Order;

/**
 * @class Colleague
 * @brief Abstract base class for colleagues in the Mediator pattern.
 *
 * Colleague represents a participant in the Mediator pattern, which collaborates with other colleagues
 * through a mediator to achieve a common goal.
 */
class Colleague {
protected:
    Mediator* mediator; ///< A pointer to the Mediator that facilitates communication.
    Order* order;       ///< A pointer to the Order associated with this Colleague.

public:
    /**
     * @brief Constructor for the Colleague class.
     * @param mediator A pointer to the Mediator used for communication with other colleagues.
     */
    Colleague(Mediator* mediator);

    /**
     * @brief Notify the Mediator that this colleague has changed state or data.
     *
     * This method is called when the state or data of the colleague has changed and needs to inform
     * the Mediator.
     */
    virtual void changed();

    /**
     * @brief Set the Order associated with this Colleague.
     * @param order A pointer to the Order to be associated with this colleague.
     */
    void setOrder(Order* order);

    /**
     * @brief Get the Order associated with this Colleague.
     * @return A pointer to the Order associated with this colleague.
     */
    Order* getOrder();
};

#endif // COLLEAGUE_H