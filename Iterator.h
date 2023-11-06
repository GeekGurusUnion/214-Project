#ifndef ITERATOR_H
#define ITERATOR_H
// Iterator (Iterator) [interface]
/**
 * @file Iterator.h
 * @brief Declaration of the Iterator class, an interface for the Iterator pattern.
 */

/**
 * @class Iterator
 * @brief An interface representing an iterator for a collection of elements.
 *
 * Iterator provides a common interface for iterating over elements in a collection without exposing
 * the underlying structure of the collection. Concrete iterator classes implement these methods for
 * specific collections.
 */
class Iterator {
public:
    /**
     * @brief Default constructor for the Iterator class.
     */
    Iterator() {};

    /**
     * @brief Virtual destructor for the Iterator class.
     */
    virtual ~Iterator() {};

    /**
     * @brief Check if there is another element to iterate over.
     * @return `true` if there is another element to iterate over, `false` otherwise.
     */
    virtual bool hasNext() = 0;

    /**
     * @brief Get the next element in the collection.
     * @return A pointer to the next element in the collection.
     */
    virtual void* next() = 0;

    /**
     * @brief Reset the iterator to the beginning of the collection.
     * @return A pointer to the first element in the collection.
     */
    virtual void* first() = 0;
};

#endif // ITERATOR_H
