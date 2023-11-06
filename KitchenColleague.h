#ifndef KITCHEN_COLLEAGUE_H
#define KITCHEN_COLLEAGUE_H
// ConcreteColleague
/**
 * @file KitchenColleague.h
 * @brief Declaration of the KitchenColleague class, a concrete implementation of the Colleague in the Mediator pattern.
 */

#include "Colleague.h"

/**
 * @class KitchenColleague
 * @brief A concrete implementation of the Colleague representing a colleague in the kitchen.
 *
 * KitchenColleague is a specific colleague in the Mediator pattern, representing an entity responsible for
 * actions related to the kitchen and order preparation in a restaurant.
 */
class KitchenColleague : public Colleague {
public:
    /**
     * @brief Constructor for the KitchenColleague class.
     * @param mediator A pointer to the Mediator used for communication with other colleagues.
     */
    KitchenColleague(Mediator* mediator);
};

#endif // KITCHEN_COLLEAGUE_H
