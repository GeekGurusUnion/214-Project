#ifndef COMMAND_H
#define COMMAND_H

// Command (Command) [interface]

class RestaurantTable;
class MenuItem;

class Command {
    public: 
        virtual void execute(RestaurantTable*, MenuItem*) = 0;
};

#endif // COMMAND_H
