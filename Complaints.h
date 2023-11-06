#ifndef COMPLAINTS_H
#define COMPLAINTS_H

#include "Command.h"

class Complaints : public Command {
    public:
        Complaints(Waiter* w);
        void execute(RestaurantTable* rt, std::string complaint);
};

#endif // COMPLAINTS_H