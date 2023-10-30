#ifndef ITERATOR_H
#define ITERATOR_H

// Iterator (Iterator) [interface]

class Iterator {
    public:
        virtual bool hasNext() = 0;
        virtual void* next() = 0;
        virtual bool isAvailable();
};

#endif // ITERATOR_H