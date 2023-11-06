#ifndef WAITER_ITERATOR_H
#define WAITER_ITERATOR_H

/**
 * @file WaiterIterator.h
 * @brief Definition of the WaiterIterator class.
 */

/**
 * @class WaiterIterator
 * @brief Represents an iterator for a collection of Waiters.
 *
 * This class is a concrete implementation of the Iterator interface,
 * providing the ability to iterate over a collection of Waiters.
 */

// ConcreteIterator (Iterator)

#include <vector>
#include "Iterator.h"
#include "Waiter.h"

class WaiterIterator : public Iterator {
private:
    /**
     * @var waiters
     * @brief A vector of Waiter pointers.
     */
    std::vector<Waiter*> waiters;

    /**
     * @var position
     * @brief The current position in the iterator.
     */
    int position = 0;

public:
    /**
     * @brief Constructor for WaiterIterator.
     * @param waiters A vector of Waiter pointers to iterate over.
     */
    WaiterIterator(std::vector<Waiter*> waiters);

    /**
     * @brief Destructor for WaiterIterator.
     */
    ~WaiterIterator();

    /**
     * @brief Move the iterator to the first element.
     * @return Pointer to the first element in the collection.
     */
    void* first();

    /**
     * @brief Get the current Waiter item in the iteration.
     * @return Pointer to the current Waiter.
     */
    Waiter* currentItem();

    /**
     * @brief Check if there is a next item in the collection.
     * @return True if there is a next item, false otherwise.
     */
    bool hasNext();

    /**
     * @brief Move the iterator to the next item in the collection.
     * @return Pointer to the next element in the collection.
     */
    void* next();

    /**
     * @brief Check if a specific Waiter is available in the collection.
     * @param waiter Pointer to the Waiter to check availability.
     * @return True if the Waiter is available in the collection, false otherwise.
     */
    bool isAvailable(Waiter* waiter);

    /**
     * @brief Reset the iterator to the beginning of the collection.
     */
    void reset();


    /**
     * @note The following functions are intended for testing purposes.
     */
    // * Testing * //

    /**
     * @brief Check if a Waiter with the specified name exists in the collection.
     * @param name Name of the Waiter to check.
     * @return True if a Waiter with the specified name exists, false otherwise.
     */
    bool getWaiter(std::string name);

    // * end of testing * //
};

#endif // WAITER_ITERATOR_H
