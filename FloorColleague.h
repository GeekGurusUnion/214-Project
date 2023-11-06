#ifndef FLOOR_COLLEAGUE_H
#define FLOOR_COLLEAGUE_H
//ConcreteColleague
/**
 * @file FloorColleague.h
 * @brief Declaration of the FloorColleague class, a concrete implementation of the Colleague in the Mediator pattern.
 */

#include "Colleague.h"

/**
 * @class FloorColleague
 * @brief A concrete implementation of the Colleague representing a colleague on the restaurant floor.
 *
 * FloorColleague is a specific colleague in the Mediator pattern, representing an entity responsible for
 * actions related to restaurant floor management and customer service.
 */
class FloorColleague : public Colleague {
public:
    /**
     * @brief Constructor for the FloorColleague class.
     * @param mediator A pointer to the Mediator used for communication with other colleagues.
     */
    FloorColleague(Mediator* mediator);
};

#endif // FLOOR_COLLEAGUE_H

