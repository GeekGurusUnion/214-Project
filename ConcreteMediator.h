#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H
//concrete mediator
/**
 * @file ConcreteMediator.h
 * @brief Declaration of the ConcreteMediator class, which is a concrete implementation of the Mediator.
 */

#include "Mediator.h"

/**
 * @class ConcreteMediator
 * @brief A concrete implementation of the Mediator interface.
 *
 * ConcreteMediator is a specific implementation of the Mediator pattern, responsible for coordinating
 * communication between colleagues (Colleague instances) within a system.
 */
class ConcreteMediator : public Mediator {
public:
    /**
     * @brief Constructor for the ConcreteMediator class.
     */
    ConcreteMediator();
};

#endif // CONCRETEMEDIATOR_H