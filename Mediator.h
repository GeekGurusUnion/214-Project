#ifndef MEDIATOR_H
#define MEDIATOR_H

// Mediator (Mediator) [interface]

class Colleague;
#include <vector>

class Mediator {
    private:
        std::vector<Colleague*> colleagues;
    public:
        Mediator() {};
        virtual ~Mediator() {
            colleagues.clear();
        };
        void notify(Colleague* colleague);
        virtual void addColleague(Colleague* colleague);
};

#endif // MEDIATOR_H
