#ifndef COMMAND_H
#define COMMAND_H

// Command (Command) [interface]

class Command {
    public: 
        virtual void execute() = 0;
};

#endif // COMMAND_H
