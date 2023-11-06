#ifndef FLOOR_COLLEAGUE_H
#define FLOOR_COLLEAGUE_H
//ConcreteColleague (Mediator)

/**
 * @file FloorColleague.h
 * @brief Declaration of the FloorColleague class, a concrete implementation of the Colleague in the Mediator pattern.
 */

#include "Colleague.h"
#include "ServeOrder.h"

/**
 * @class FloorColleague
 * @brief A concrete implementation of the Colleague representing a colleague on the restaurant floor.
 *
 * FloorColleague is a specific colleague in the Mediator pattern, representing an entity responsible for
 * actions related to restaurant floor management and customer service.
 */
class FloorColleague : public Colleague {
private:
    /**
     * @var order
     * @brief The order to be handled by the colleague.
     */
    ServeOrder* serveOrderCommand = nullptr;
public:
    /**
     * @brief Constructor for the FloorColleague class.
     * @param mediator A pointer to the Mediator used for communication with other colleagues.
     */
    FloorColleague(Mediator* mediator);

    /**
     * @brief Destructor for the FloorColleague class.
     */
    ~FloorColleague();

    void handleOrder();
};

#endif // FLOOR_COLLEAGUE_H

