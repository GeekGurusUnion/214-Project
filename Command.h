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
        Command(Waiter* waiter) : waiter(waiter) {};
        virtual void execute(RestaurantTable*, MenuItem*) = 0;
        virtual void execute(RestaurantTable* rt, std::string menuItem, std::string customization) {};
        virtual ~Command() {};

        // * testing * //
        virtual Waiter* getWaiter() const {
            return waiter;
        }
};

#endif // COMMAND_H
