#ifndef COMMAND_H
#define COMMAND_H

// Command (Command) [interface]

class RestaurantTable;
class MenuItem;
class Waiter;

class Command {
    protected:
        Waiter* waiter;
    public: 
        virtual void execute(RestaurantTable*, MenuItem*) = 0;
        virtual ~Command() {};
};

#endif // COMMAND_H
