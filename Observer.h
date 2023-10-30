#ifndef OBSERVER_H
#define OBSERVER_H

// Observer (Observer) [interface]

#include <iostream>
#include "Table.h"

class Observer {
    public:
        virtual void update() = 0;
};

#endif // OBSERVER_H