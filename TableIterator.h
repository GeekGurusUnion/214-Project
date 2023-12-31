#ifndef TABLE_ITERATOR_H
#define TABLE_ITERATOR_H
// ConcreteIterator (Iterator)

/**
 * @file TableIterator.h
 * @brief Definition of the TableIterator class.
 */

#include "Iterator.h"
#include "RestaurantTable.h"
#include <vector>

/**
 * @class TableIterator
 * @brief Represents an iterator for a collection of RestaurantTables.
 *
 * This class is a concrete implementation of the Iterator interface,
 * providing the ability to iterate over a collection of RestaurantTables.
 */
class TableIterator : public Iterator {
private:
    /**
     * @var tables
     * @brief A vector of RestaurantTable pointers to iterate over.
     */
    std::vector<RestaurantTable*> tables;

    /**
     * @var position
     * @brief The current position in the iterator.
     */
    int position = 0;

public:
    /**
     * @brief Constructor for TableIterator.
     * @param tables A vector of RestaurantTable pointers to iterate over.
     */
    TableIterator(std::vector<RestaurantTable*> tables);

    /**
     * @brief Destructor for TableIterator.
     */
    ~TableIterator();

    /**
     * @brief Move the iterator to the first element.
     * @return Pointer to the first element in the collection.
     */
    void* first();

    /**
     * @brief Get the current RestaurantTable item in the iteration.
     * @return Pointer to the current RestaurantTable.
     */
    RestaurantTable* currentItem();

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
     * @brief Reset the iterator to the beginning of the collection.
     */
    void reset();
};

#endif // TABLE_ITERATOR_H
