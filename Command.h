#ifndef COMMAND_H
#define COMMAND_H

// Command (Command) [interface]

#include <iostream>

class RestaurantTable;
class MenuItem;
class Waiter;

class Command {
    protected:
        Waiter* waiter;
    public: 
        Command(Waiter* waiter) {
            this->waiter = waiter;
        }
        virtual void execute(RestaurantTable*, MenuItem*) = 0;
        virtual ~Command() {};
};

#endif // COMMAND_H
