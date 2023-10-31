#ifndef COMMAND_H
#define COMMAND_H

// Command (Command) [interface]

#include "RestaurantTable.h"

class Command {
    public: 
        virtual void execute(RestaurantTable*, MenuItem*) = 0;
};

#endif // COMMAND_H
