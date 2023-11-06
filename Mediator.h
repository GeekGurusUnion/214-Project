#ifndef MEDIATOR_H
#define MEDIATOR_H
// Mediator (Mediator) [interface]
/**
 * @file Mediator.h
 * @brief Declaration of the Mediator class, an interface for the Mediator pattern.
 */

class Colleague;
#include <vector>

/**
 * @class Mediator
 * @brief An interface representing a mediator for communication among colleagues.
 *
 * Mediator defines a common interface for objects that facilitate communication and coordination among
 * different colleagues (objects) in a system. It manages a list of colleagues and provides a way for
 * them to notify each other.
 */
class Mediator {
private:
    std::vector<Colleague*> colleagues; ///< A container to store the colleagues.

public:
    /**
     * @brief Default constructor for the Mediator class.
     */
    Mediator() {};

    /**
     * @brief Virtual destructor for the Mediator class.
     *
     * Clears the list of colleagues when the mediator is destroyed.
     */
    virtual ~Mediator() {
        colleagues.clear();
    };

    /**
     * @brief Notify a colleague within the mediator.
     * @param colleague A pointer to the colleague that needs to be notified.
     */
    void notify(Colleague* colleague);

    /**
     * @brief Add a colleague to the mediator's list.
     * @param colleague A pointer to the colleague to be added to the mediator.
     */
    virtual void addColleague(Colleague* colleague);
};

#endif // MEDIATOR_H
