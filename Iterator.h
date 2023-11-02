#ifndef ITERATOR_H
#define ITERATOR_H

// Iterator (Iterator) [interface]

class Iterator {
    public:
        virtual ~Iterator() {};
        virtual bool hasNext() = 0;
        virtual void* next() = 0;
        virtual void* first() = 0;
};

#endif // ITERATOR_H